
set(CURRENT_PROJECT ${PROJECT_NAME}_module)
message(STATUS "start ${CURRENT_PROJECT}")

set(SOURCE_FILES module_interface.cpp)

add_library(${CURRENT_PROJECT} SHARED ${SOURCE_FILES})

target_link_libraries(${CURRENT_PROJECT} ${CMAKE_JS_LIB} ${PROJECT_NAME}_lib)

# Include N-API wrappers
target_include_directories(${CURRENT_PROJECT} PUBLIC "${CMAKE_SOURCE_DIR}/node_modules/node-addon-api")
target_include_directories(${CURRENT_PROJECT} PUBLIC "${CMAKE_SOURCE_DIR}/node_modules/node-addon-api/src")

# This line will give our library file a .node extension without any "lib" prefix
set_target_properties(${CURRENT_PROJECT} PROPERTIES PREFIX "" SUFFIX ".node")
#target_link_libraries(${CURRENT_PROJECT} ${CMAKE_JS_LIB} ${PROJECT_NAME}_lib)

message(STATUS "end ${CURRENT_PROJECT}")