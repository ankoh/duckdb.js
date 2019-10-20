#include "flatbuffers/flatbuffers.h"
#include "duckdb.h" 

#include <unordered_map>
#include <memory>

namespace duckdb_web {

class WebAPI {
    public:
    using DatabasePtr = void*;
    using ConnectionPtr = void*;
    using ResultPtr = void*;

    protected:
    /// The database pointer
    duckdb_database database;
    /// The detached buffers
    std::unordered_map<ResultPtr, std::unique_ptr<flatbuffers::DetachedBuffer>> detachedBuffers;

    public:
    /// Constructor
    WebAPI();
    /// Destructor
    ~WebAPI();

    /// Create a database connection
    ConnectionPtr connect();
    /// Closes the specified connection
    void disconnect(ConnectionPtr conn);

    /// Execute a query
    ResultPtr query(ConnectionPtr conn, const char* query);
    /// Destroys the result
    void destroy_result(ResultPtr);
    /// Get the result size
    uint32_t get_result_size(ResultPtr result);
};

}
