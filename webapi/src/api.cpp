#include "duckdb_webapi/api.h"

#include "duckdb.hpp"

#include "spdlog/spdlog.h"

#include <cstdio>
#include <iostream>
#include <memory>
#include <optional>
#include <string_view>
#include <unordered_map>

using namespace duckdb_webapi;

/// Reset the response
void WebAPI::Response::clear() {
    status_code = proto::StatusCode::SUCCESS;
    error.clear();
    data = {};
}

/// Write the packed response
void WebAPI::Response::writePacked(WebAPI::Response::Packed& packed) {
    packed.error = error.empty() ? 0 : reinterpret_cast<uintptr_t>(error.data());
    packed.data = reinterpret_cast<uintptr_t>(data.data());
    packed.data_size = data.size();
    packed.status_code = static_cast<uint32_t>(status_code);
}

/// Request succeeded
void WebAPI::Response::requestSucceeded(nonstd::span<std::byte> d) {
    clear();
    status_code = proto::StatusCode::SUCCESS;
    data = d;
}

void WebAPI::Response::requestFailed(proto::StatusCode status, std::string err) {
    clear();
    status_code = status;
    error = move(err);
}

/// Constructor
WebAPI::Response::Response(WebAPI::Session& session): session(session), status_code(), error(), data() {}

/// Constructor
WebAPI::Response::~Response() {
    clear();
}

/// Constructor
WebAPI::Session::Session(std::shared_ptr<duckdb::DuckDB> database): database(std::move(database)), buffers(), response(*this), nextQueryID() {}

/// Destructor
WebAPI::Session::~Session() {}

/// Write the packed response
void WebAPI::Session::writePackedResponse(Response::Packed& packed) {
    response.writePacked(packed);
}

/// Encode a message
nonstd::span<std::byte> WebAPI::Session::serializeMessage(google::protobuf::MessageLite& msg) {
    // Serialize the message
    auto size = msg.ByteSizeLong();
    auto bytes = std::unique_ptr<std::byte[]>(new std::byte[size]);
    msg.SerializeToArray(bytes.get(), size);

    // Register the buffer
    return registerBuffer(std::move(bytes), size);
}

/// Register a buffer
nonstd::span<std::byte> WebAPI::Session::registerBuffer(std::unique_ptr<std::byte[]> data, size_t dataSize) {
    Buffer buffer{std::move(data), dataSize};
    auto span = buffer.asSpan();
    auto ptr = span.data();
    buffers.insert({ptr, std::move(buffer)});
    return span;
}

/// Release a buffer
void WebAPI::Session::releaseBuffer(void* data) {
    buffers.erase(data);
}

/// Run a query
void WebAPI::Session::runQuery(std::string_view text) {
//    auto queryID = allocateQueryID();
//
//    // Create a new connection
//    duckdb::Connection conn{*database};
//    auto result = conn.SendQuery(std::string{text});
//
//    // Query failed?
//    if (!result->success) {
//        response.requestFailed(proto::StatusCode::ERROR, result->error);
//        return;
//    }
//
//    // Encode the result
//    google::protobuf::Arena arena;
//    auto msg = encodeQueryResult(arena, *result, queryID);
//    auto buffer = serializeMessage(*msg);
//
//    // Return buffer
//    response.requestSucceeded(buffer);
}

/// Constructor
WebAPI::WebAPI(): database(std::make_shared<duckdb::DuckDB>()), sessions() {}

/// Create a session
WebAPI::Session& WebAPI::createSession() {
    auto session = std::make_unique<WebAPI::Session>(database);
    auto sessionPtr = session.get();
    sessions.insert({sessionPtr, move(session)});
    return *sessionPtr;
}

/// End a session
void WebAPI::endSession(Session* session) {
    sessions.erase(session);
}
