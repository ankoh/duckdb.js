#!/bin/bash

PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )/../"

DUCKDB_WEB_SOURCE_DIR="${PROJECT_ROOT}/duckdb_web"
DUCKDB_WEB_BUILD_DIR="${PROJECT_ROOT}/duckdb_web/build/emscripten"
DEMO_SOURCE_DIR="${PROJECT_ROOT}/demo"
DEMO_PUBLIC_DIR="${DEMO_SOURCE_DIR}/public/lib"

[ ! -z "${EMSDK}" ] \
    && { echo "[ OK  ] Test environment: EMSDK"; } \
    || { \
        echo "[ ERR ] Test environment: EMSDK"; \
        echo "You need to source emsdk_env.sh before running this script."; \
        exit 1; \
    }
[ -x "$(command -v emconfigure)" ] \
    && { echo "[ OK  ] Test command: emconfigure"; } \
    || { echo "[ ERR ] Test command: emconfigure"; exit 1; }
[ -x "$(command -v emmake)" ] \
    && { echo "[ OK  ] Test command: emmake"; } \
    || { echo "[ ERR ] Test command: emmake"; exit 1; }

mkdir -p ${DUCKDB_WEB_BUILD_DIR}
cd ${DUCKDB_WEB_BUILD_DIR}

emconfigure cmake -DCMAKE_BUILD_TYPE=Release ${DUCKDB_WEB_SOURCE_DIR} \
    && { echo "[ OK  ] Build configuration"; } \
    || { echo "[ ERR ] Build configuration"; exit 1; }

emmake make -j$(nproc) duckdb_web \
    && { echo "[ OK  ] Build project"; } \
    || { echo "[ ERR ] Build project"; exit 1; }

mkdir -p ${DEMO_PUBLIC_DIR}
cp ${DUCKDB_WEB_BUILD_DIR}/duckdb_web.{wasm,js} ${DEMO_PUBLIC_DIR}

cd ${DUCKDB_WEB_SOURCE_DIR}
