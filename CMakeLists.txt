cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(PROJECT_NAME RDEngine)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.c src/*.h src/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(Libs/glfw1)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(Libs/glad)
target_link_libraries(${PROJECT_NAME} Glad)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/bin")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)