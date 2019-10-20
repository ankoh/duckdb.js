#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)/.."

PROTO_DIR="${PROJECT_ROOT}/proto"
DUCKDB_WEB_SOURCE_DIR="${PROJECT_ROOT}/duckdb_web"
DUCKDB_WEB_PROTO_DIR="${DUCKDB_WEB_SOURCE_DIR}/include/duckdb_web/proto"
DEMO_SOURCE_DIR="${PROJECT_ROOT}/demo"
DEMO_PROTO_DIR="${DEMO_SOURCE_DIR}/src/proto"

[ -x "$(command -v flatc)" ] \
    && { echo "[ OK  ] Command: flatc"; } \
    || { echo "[ ERR ] Command: flatc"; exit 1; }

for PROTO_FILE in ${PROTO_DIR}/*; do
    TMP=$(mktemp -d)
    PROTO_FILE_NAME=$(basename -- "${PROTO_FILE}")
    PROTO_FILE_NAME="${PROTO_FILE_NAME%.*}"
    PROTO_TMP="${TMP}/${PROTO_FILE_NAME}.fbs"
    DEMO_PROTO_OUT="${DEMO_PROTO_DIR}/${PROTO_FILE_NAME}_generated.ts"
    DEMO_PROTO_TMP="${TMP}/${PROTO_FILE_NAME}.ts"

    flatc -I ${PROTO_DIR} -o ${DUCKDB_WEB_PROTO_DIR} ${PROTO_FILE} --cpp --no-prefix --scoped-enums \
        && { echo "[ OK  ] ${PROTO_FILE}: C++"; } \
        || { echo "[ ERR ] ${PROTO_FILE}: C++"; exit 1; }

    sed -e "s/^namespace.*$//g" ${PROTO_FILE} > ${PROTO_TMP} \
        && flatc -I ${PROTO_DIR} -o ${DEMO_PROTO_DIR} ${PROTO_TMP} --ts --no-fb-import \
        && mv ${DEMO_PROTO_OUT} ${DEMO_PROTO_TMP} \
        && echo "/* eslint-disable */" > ${DEMO_PROTO_OUT} \
        && echo "import { flatbuffers } from \"flatbuffers\";" >> ${DEMO_PROTO_OUT} \
        && cat ${DEMO_PROTO_TMP} >> ${DEMO_PROTO_OUT} \
        && { echo "[ OK  ] ${PROTO_FILE}: Typescript"; } \
        || { echo "[ ERR ] ${PROTO_FILE}: Typescript"; exit 1; }

    rm -r ${PROTO_TMP}
done
