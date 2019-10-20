#include "duckdb_web/api.hpp" 
#include "duckdb_web/proto/duckdb_web_generated.h"
#include "spdlog/spdlog.h"

namespace fb = flatbuffers;

namespace duckdb_web {

WebAPI::WebAPI() {
    if (duckdb_open(nullptr, &database) == DuckDBSuccess) {
        spdlog::info("opened database");
    } else {
        spdlog::error("failed to open database");
    }
}

WebAPI::~WebAPI() {
    for (auto& d: detachedBuffers) {
        d.second.reset();
    }
}

WebAPI::ConnectionPtr WebAPI::connect() {
    WebAPI::ConnectionPtr conn;
    if (duckdb_connect(database, &conn) == DuckDBSuccess) {
        spdlog::info("created database connection");
    } else {
        spdlog::error("failed to create database connection");
    }
    return conn;
}

void WebAPI::disconnect(ConnectionPtr conn) {
    duckdb_disconnect(&conn);
}

WebAPI::ResultPtr WebAPI::query(ConnectionPtr conn, const char* query) {
    spdlog::info(std::string("running query: ") + query);

    // Execute the query
    duckdb_result queryResult;
    if (duckdb_query(conn, query, &queryResult) != DuckDBSuccess) {
        spdlog::error("failed to execute query");
        return nullptr;
    }

    // Encode the query result as flatbuffer
    fb::FlatBufferBuilder builder{1024};
 
//  This wont work...
//
//     // Encode the error message
//     std::optional<fb::Offset<fb::String>> resultError;
//     if (!!queryResult.error_message) {
//         resultError = builder.CreateString(queryResult.error_message);
//     }
// 
//     // Encode the columns
//     std::vector<fb::Offset<proto::DuckDBColumn>> columns;
//     for (unsigned i = 0; i < queryResult.column_count; ++i) {
//         char* buffer;
//         builder.CreateUninitializedVector(queryResult.columns[i].
//     }
// 
//     // Create the buffer builder
//     duckdb_web::proto::DuckDBResultBuilder resultBuilder(builder);
// 
//     auto result = resultBuilder.Finish();
// 
//     // Finish the flatbuffer
//     builder.Finish(result);
//     auto detachedBuffer = std::make_unique<fb::DetachedBuffer>(builder.Release());    
//     auto data = detachedBuffer->data();
//     detachedBuffers.insert({data, std::move(detachedBuffer)});
//    return data;

    return nullptr;
}

void WebAPI::destroy_result(ResultPtr result) {
    auto iter = detachedBuffers.find(result);
    if (iter != detachedBuffers.end()) {
        detachedBuffers.erase(iter);
    }
}

uint32_t WebAPI::get_result_size(ResultPtr result) {
    auto iter = detachedBuffers.find(result);
    if (iter != detachedBuffers.end()) {
        return iter->second->size();
    }
    return 0;
}


}
