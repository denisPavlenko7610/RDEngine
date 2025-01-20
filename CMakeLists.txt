cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(PROJECT_NAME RDEngine)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(Libs/glfw1)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(Libs/glad)
target_link_libraries(${PROJECT_NAME} Glad)