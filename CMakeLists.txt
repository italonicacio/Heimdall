cmake_minimum_required (VERSION 3.22)

project(Heimdall CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE FALSE)


file(GLOB SOURCES "src/*.cpp")

add_executable(Heimdall ${SOURCES})

target_include_directories(Heimdall PUBLIC ${CMAKE_SOURCE_DIR}/include)


# add_subdirectory(tests)