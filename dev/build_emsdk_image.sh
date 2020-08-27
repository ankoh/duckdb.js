#!/bin/bash
set -euo pipefail

PROJECT_ROOT="$(cd $(dirname "$BASH_SOURCE[0]") && cd .. && pwd)" &> /dev/null

EMSDK_COMMIT="1.40.1"
DOCKER_IMAGE_NAME="duckdbjs-emsdk"
DOCKER_IMAGE_NAMESPACE="ankoh"
DOCKER_IMAGE_TAG="${EMSDK_COMMIT}"

set -x

cd ${PROJECT_ROOT} && \
    tar -cvf - ./dev/Dockerfile.emsdk | docker build \
        -t ${DOCKER_IMAGE_NAMESPACE}/${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG} \
        -f ./dev/Dockerfile.emsdk \
        --build-arg EMSDK_COMMIT="${EMSDK_COMMIT}" \
        -

