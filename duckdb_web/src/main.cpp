#include "duckdb_web/api.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"

namespace {

// The instance
std::unique_ptr<duckdb_web::WebAPI> instance;

}

extern "C" {

int main() {
    // Prepare the logger
    auto logSink = std::make_shared<spdlog::sinks::stderr_sink_st>();
    auto logger = std::make_shared<spdlog::logger>("console", logSink);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern(R"RAW({"time":"%T","level":"%l","message":"%v"})RAW");
    spdlog::set_default_logger(logger);
    spdlog::info("initialized logger");
       
    // Create the instance
    instance = std::make_unique<duckdb_web::WebAPI>();
    spdlog::info("initialized web api");
    return 0;
}

/// Connect to a database
void* duckdb_web_connect() {
    return instance->connect();
}

/// Disconnect from a database
void duckdb_web_disconnect(void* connection) {
    instance->disconnect(connection);
}

/// Query a database
void* duckdb_web_query(void* connection, const char* query) {
    return instance->query(connection, query);
}

/// Destroy a query result
void duckdb_web_destroy_result(void* result) {
    return instance->destroy_result(result);
}

/// Get the result size
uint32_t duckdb_web_get_result_size(void* result) {
    return instance->get_result_size(result);
}

}
