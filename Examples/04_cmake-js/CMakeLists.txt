set (CURRENT_PROJECT "example04")

project (${CURRENT_PROJECT})

cmake_minimum_required(VERSION 3.0)

if (CMAKE_JS_VERSION)
    message(STATUS "Yes ${CMAKE_JS_INCLUDE}" )
else()
    message(STATUS "No ${CMAKE_JS_INCLUDE}" )
endif()


if(CMAKE_BUILD_TYPE MATCHES Debug)
    set (CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -fno-exceptions")
else()
    set (CMAKE_CXX_FLAGS "-O2 -DNDEBUG -Wno-deprecated-declarations -fno-exceptions")
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/src/CMakeLists.txt)
