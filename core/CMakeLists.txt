# Use project versions
# cmake --help-policy CMP0048
if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

# ---------------------------------------------------------------------------

project("duckdb_wasm" VERSION 0.1)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS -std=c++17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")

# ---------------------------------------------------------------------------
# Parallelism

include(ProcessorCount)
ProcessorCount(NPROCS)
set(CMAKE_BUILD_PARALLEL_LEVEL ${NPROCS})

# ---------------------------------------------------------------------------
# Threading

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# ---------------------------------------------------------------------------
# CMake includes

include("${CMAKE_SOURCE_DIR}/cmake/clang-tidy.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/duckdb.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/protobuf.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/googletest.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/spdlog.cmake")

# ---------------------------------------------------------------------------
# Proto project

add_subdirectory(
    "${CMAKE_SOURCE_DIR}/../proto/lib/cpp"
    "${CMAKE_BINARY_DIR}/proto"
)

# ---------------------------------------------------------------------------
# Headers

include_directories(
    "${CMAKE_SOURCE_DIR}/include"
    "${DUCKDB_INCLUDE_DIR}"
)

# ---------------------------------------------------------------------------
# Library

add_library(duckdb_wasm_core
    ${CMAKE_SOURCE_DIR}/../submodules/duckdb/src/amalgamation/duckdb.cpp
    ${CMAKE_SOURCE_DIR}/src/api.cpp
    ${DUCKDB_SOURCE_FILE}
)

target_link_libraries(duckdb_wasm_core
    duckdb_wasm_proto
    protobuf
    spdlog
    Threads::Threads
)

# ---------------------------------------------------------------------------
# API Proxy

add_executable(duckdb_wasm
    ${CMAKE_SOURCE_DIR}/src/api_proxy.cpp
)

target_link_libraries(duckdb_wasm duckdb_wasm_core)

if(EMSCRIPTEN)
    # SAFE_HEAP breaks duckdb 0.2
    # -s SAFE_HEAP=1
    set_target_properties(duckdb_wasm PROPERTIES
        LINK_FLAGS "\
            -s ENVIRONMENT='web,worker' \
            -s USE_PTHREADS=1 \
            -Wl,--shared-memory,--no-check-features \
            -s DISABLE_EXCEPTION_CATCHING=0 \
            -s ASSERTIONS=1 \
            -s MODULARIZE=1 \
            -s EXPORTED_FUNCTIONS='[ \
                _main, \
                _malloc, \
                _free
            ]' \
            -s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\",\"allocate\",\"ALLOC_STACK\", \"ALLOC_NORMAL\"]' \
        "
    )
endif()

# ---------------------------------------------------------------------------
# Tester

add_executable(tester
    ${CMAKE_SOURCE_DIR}/test/tester.cc
)
target_link_libraries(tester duckdb_wasm_core gtest gmock Threads::Threads)

enable_testing()
add_test(duckdb_wasm tester)

