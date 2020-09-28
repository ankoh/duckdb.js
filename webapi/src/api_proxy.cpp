#include <iostream>
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#include "duckdb_webapi/proto/api.pb.h"
#include "duckdb_webapi/api.h"

using namespace duckdb_webapi;

static std::unique_ptr<WebAPI> instance;

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    // Prepare the logger
    auto logSink = std::make_shared<spdlog::sinks::stderr_sink_st>();
    auto logger = std::make_shared<spdlog::logger>("console", logSink);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern(R"RAW({"time":"%T","level":"%l","message":"%v"})RAW");
    spdlog::set_default_logger(logger);
    spdlog::info("initialized logger");

    // Create the instance
    instance = std::make_unique<WebAPI>();
    spdlog::info("initialized web api");
    return 0;
}

extern "C" {

/// Create a session
WebAPI::Session* duckdb_create_session() {
    return &instance->createSession();
}

/// End a session
void duckdb_end_session(WebAPI::Session* session) {
    instance->endSession(session);
}

/// Release a buffer
void duckdb_register_buffer(WebAPI::Session* session, void* buffer_ptr, unsigned buffer_length) {
    std::unique_ptr<std::byte[]> bytes{static_cast<std::byte*>(buffer_ptr)};
    session->registerBuffer(std::move(bytes), buffer_length);
}

/// Release a buffer
void duckdb_release_buffer(WebAPI::Session* session, void* buffer) {
    session->releaseBuffer(buffer);
}

/// Run a query
void duckdb_run_query(WebAPI::Response::Packed* response, WebAPI::Session* session, const char* text) {
    session->runQuery(text);
    session->writePackedResponse(*response);
}

}
