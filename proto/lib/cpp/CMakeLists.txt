project(duckdb_wasm_proto)
cmake_minimum_required(VERSION 3.10)

# ---------------------------------------------------------------------------
# Library

add_library(duckdb_wasm_proto STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/duckdb_wasm/proto/api.pb.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/include/duckdb_wasm/proto/query_plan.pb.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/include/duckdb_wasm/proto/query_result.pb.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/include/duckdb_wasm/proto/sql_type.pb.cc
)
target_include_directories(duckdb_wasm_proto INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(duckdb_wasm_proto protobuf)

