pipeline {
    agent {
        dockerfile {
            filename 'Dockerfile.emsdk'
            dir './dev/'
            additionalBuildArgs '--build-arg EMSDK_VERSION=2.0.4'
            args '-v $HOME/.emscripten_cache:/mnt/emscripten_cache -v $HOME/.npm_cache:/mnt/npm_cache'
        }
    }

    environment {
        EM_CACHE = '/mnt/emscripten_cache'
        NPM_CACHE = '/mnt/npm_cache'
    }

    stages {
        stage('Configure') {
            steps {
                sh 'chown -R "$USER" /mnt/npm_cache /mnt/emscripten_cache'
                sh 'git submodule update --init --recursive'
                sh 'mkdir -p ./core/build/emscripten'
            }
        }

        stage('Build/WebAPI') {
            steps {
                sh '''#!/bin/bash
                    source /opt/env.sh
                    emcmake cmake -S./core/ -B./core/build/emscripten -DCMAKE_BUILD_TYPE=Release
                '''
                sh '''#!/bin/bash
                    source /opt/env.sh
                    emmake make -C./core/build/emscripten -j$(nproc)
                    cp ./core/build/emscripten/dashql_core.{wasm,js,worker.js} ./app/public/core/
                '''
            }
        }

        stage ('Build/Lib') {
            steps {
                dir('./app') {
                    sh 'npm ci --cache ${NPM_CACHE}'
                    sh 'npm run build'
                }
            }
        }
    }
}
