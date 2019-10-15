include(ExternalProject)

ExternalProject_Add(
    spdlog_ep
    PREFIX "${CMAKE_BINARY_DIR}/modules/spdlog"
    SOURCE_DIR "${CMAKE_SOURCE_DIR}/modules/spdlog"
    INSTALL_DIR "${CMAKE_BINARY_DIR}/modules/spdlog/install"
    CMAKE_ARGS
        -G${CMAKE_GENERATOR}
        -DCMAKE_CXX_STANDARD=17
        -DCMAKE_CXX_FLAGS=-std=c++17
        -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
        -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
        -DCMAKE_BUILD_TYPE=Release
        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/modules/spdlog/install
        -DSPDLOG_INSTALL=ON
        -DSPDLOG_BUILD_SHARED=OFF
    DOWNLOAD_COMMAND ""
    UPDATE_COMMAND ""
    BUILD_BYPRODUCTS <INSTALL_DIR>/lib/libspdlog.a
)

ExternalProject_Get_Property(spdlog_ep install_dir)
set(SPDLOG_INCLUDE_DIR ${install_dir}/include)
set(SPDLOG_LIBRARY_PATH ${install_dir}/lib/libspdlog.a)
file(MAKE_DIRECTORY ${SPDLOG_INCLUDE_DIR})

add_library(spdlog STATIC IMPORTED)
set_property(TARGET spdlog PROPERTY IMPORTED_LOCATION ${SPDLOG_LIBRARY_PATH})
set_property(TARGET spdlog APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${SPDLOG_INCLUDE_DIR})

add_dependencies(spdlog spdlog_ep)
