include(ExternalProject)

# Flatbuffers library
ExternalProject_Add(
    flatbuffers_ep
    SOURCE_DIR "${CMAKE_SOURCE_DIR}/modules/flatbuffers"
    PREFIX "${CMAKE_BINARY_DIR}/modules/flatbuffers"
    INSTALL_DIR "${CMAKE_BINARY_DIR}/modules/flatbuffers/install"
    CMAKE_ARGS
        -G${CMAKE_GENERATOR}
        -DCMAKE_CXX_STANDARD=17
        -DCMAKE_CXX_FLAGS=-std=c++17
        -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
        -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
        -DCMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}
        -DCMAKE_BUILD_TYPE=Release
        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/modules/flatbuffers/install
        -DFLATBUFFERS_BUILD_TESTS=OFF
        -DFLATBUFFERS_BUILD_FLATLIB=ON
        -DFLATBUFFERS_BUILD_FLATC=OFF
        -DFLATBUFFERS_BUILD_FLATHASH=OFF
        -DFLATBUFFERS_BUILD_SHAREDLIB=OFF
        -DFLATBUFFERS_INSTALL=ON
    BUILD_COMMAND ${CMAKE_MAKE_PROGRAM} flatbuffers
    DOWNLOAD_COMMAND ""
    UPDATE_COMMAND ""
    BUILD_BYPRODUCTS
        <INSTALL_DIR>/lib/libflatbuffers.a
)

ExternalProject_Get_Property(flatbuffers_ep install_dir)
set(FLATBUFFERS_INCLUDE_DIR ${install_dir}/include)
set(FLATBUFFERS_LIBRARY_PATH ${install_dir}/lib/libflatbuffers.a)
file(MAKE_DIRECTORY ${FLATBUFFERS_INCLUDE_DIR})

add_library(flatbuffers STATIC IMPORTED)
set_property(TARGET flatbuffers PROPERTY IMPORTED_LOCATION ${FLATBUFFERS_LIBRARY_PATH})
set_property(TARGET flatbuffers APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${FLATBUFFERS_INCLUDE_DIR})

add_dependencies(flatbuffers flatbuffers_ep)

# Flatc (bypass emscripten toolchain)
ExternalProject_Add(
    flatc_ep
    SOURCE_DIR "${CMAKE_SOURCE_DIR}/modules/flatbuffers"
    PREFIX "${CMAKE_BINARY_DIR}/modules/flatc"
    INSTALL_DIR "${CMAKE_BINARY_DIR}/modules/flatc/install"
    CMAKE_ARGS
        -G${CMAKE_GENERATOR}
        -DCMAKE_CXX_STANDARD=17
        -DCMAKE_CXX_FLAGS=-std=c++17
        -DCMAKE_BUILD_TYPE=Release
        -DCMAKE_CXX_COMPILER=clang++
        -DCMAKE_C_COMPILER=clang
        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/modules/flatc/install
        -DFLATBUFFERS_BUILD_TESTS=OFF
        -DFLATBUFFERS_BUILD_FLATLIB=OFF
        -DFLATBUFFERS_BUILD_FLATC=ON
        -DFLATBUFFERS_BUILD_FLATHASH=OFF
        -DFLATBUFFERS_BUILD_SHAREDLIB=OFF
        -DFLATBUFFERS_INSTALL=ON
    BUILD_COMMAND ${CMAKE_MAKE_PROGRAM} flatc
    DOWNLOAD_COMMAND ""
    UPDATE_COMMAND ""
    BUILD_BYPRODUCTS
        <INSTALL_DIR>/bin/flatc
)

ExternalProject_Get_Property(flatc_ep install_dir)
set(FLATC ${install_dir}/bin/flatc)
