cmake_minimum_required(VERSION 3.27)
project(ProjectX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# Fetch Catch2 v3
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.3
)

FetchContent_MakeAvailable(Catch2)

# Main Executable
add_executable(ProjectX
        main.cpp
        Network.h
        Network.cpp
        User.cpp
        User.h
        Post.cpp
        Post.h
        Comment.cpp
        Comment.h
)

# Test Executable
add_executable(tests
        test.cpp
        Network.cpp
        User.cpp
        User.h
        Post.cpp
        Post.h
        Comment.cpp
        Comment.h
)

# Link test target to Catch2 with main
target_link_libraries(tests
        PRIVATE Catch2::Catch2WithMain
)

include(CTest)
enable_testing()
include(Catch)
catch_discover_tests(tests)