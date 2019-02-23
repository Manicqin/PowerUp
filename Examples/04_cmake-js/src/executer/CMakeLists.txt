set(CURRENT_PROJECT ${PROJECT_NAME}_exec)
message(STATUS "start ${CURRENT_PROJECT}")

set(SOURCE_FILES main.cpp)

add_executable(${CURRENT_PROJECT} ${SOURCE_FILES})
target_link_libraries(${CURRENT_PROJECT} ${PROJECT_NAME}_lib)