project(duckdb_web)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS -std=c++17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")

# ---------------------------------------------------------------------------
# CMake includes

include("${CMAKE_SOURCE_DIR}/cmake/clang-tidy.cmake")
include("${CMAKE_SOURCE_DIR}/modules/duckdb.cmake")
include("${CMAKE_SOURCE_DIR}/modules/spdlog.cmake")
include("${CMAKE_SOURCE_DIR}/modules/googletest.cmake")

# ---------------------------------------------------------------------------
# Library

include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(duckdb_api
    ${CMAKE_SOURCE_DIR}/src/api.cpp
)
target_link_libraries(duckdb_api duckdb spdlog)

# ---------------------------------------------------------------------------
# JS Binary

add_executable(duckdb_web
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)
target_link_libraries(duckdb_web duckdb_api)

if(DEFINED ENV{EMSDK})
    set_target_properties(duckdb_web PROPERTIES LINK_FLAGS "\
        -s MODULARIZE=1 \
        -s EXPORT_NAME=DuckDB \
        -s EXPORTED_FUNCTIONS='[\
            _main, \
            _duckdb_open, \
            _duckdb_close, \
            _duckdb_disconnect, \
            _duckdb_query, \
            _duckdb_destroy_result, \
            _duckdb_value_boolean, \
            _duckdb_value_int8, \
            _duckdb_value_int16, \
            _duckdb_value_int32, \
            _duckdb_value_int64, \
            _duckdb_value_float, \
            _duckdb_value_double, \
            _duckdb_value_varchar \
        ]' \
        -s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\", \"cwrap\"]' \
    ")
endif()

# ---------------------------------------------------------------------------
# Tester

add_executable(tester
    ${CMAKE_SOURCE_DIR}/test/tester.cpp
    ${CMAKE_SOURCE_DIR}/test/api_test.cpp
)
target_link_libraries(tester duckdb_api gtest gmock)

enable_testing()
add_test(duckdb_web tester)
