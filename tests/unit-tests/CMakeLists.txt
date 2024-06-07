


find_package(GTest 1.11)

if(NOT GTest_FOUND)
    set(FETCHCONTENT_QUIET OFF CACHE BOOL "Desabilita o modo quiet to FetchContent" FORCE)
    include(FetchContent)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
    )

    FetchContent_MakeAvailable(googletest)
endif()

add_executable(
    unit_tests
    "run-tests.cpp"
    "argument-parser-test.cpp"
    "utils-test.cpp"
    "vec-template-test.cpp"
	"vec3-test.cpp"
	"ray-test.cpp"
	"sphere-test.cpp"
	"hitable-list-test.cpp"
)

target_link_libraries(unit_tests PUBLIC Heimdall_lib gtest)

