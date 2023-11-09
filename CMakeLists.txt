cmake_minimum_required (VERSION 3.22)

project(Heimdall CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE FALSE)


file(GLOB SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "src/main.cpp")

add_library(
    Heimdall_lib 
    STATIC 
        ${SOURCES}
)

target_include_directories(Heimdall_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_target_properties( 
    Heimdall_lib
    PROPERTIES
        ENABLE_EXPORTS ON
        POSITION_INDEPENDENT_CODE ON 
)


add_executable(Heimdall "src/main.cpp")


target_link_libraries(Heimdall Heimdall_lib)

add_subdirectory(tests)