cmake_minimum_required(VERSION 3.16)
project(Test1_Client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(OpenCV REQUIRED)
find_package(GTest REQUIRED)

add_executable(smoke_test
    src/main.cpp
)

target_link_libraries(smoke_test
    PRIVATE
    Qt6::Core
    ${OpenCV_LIBS}
)

target_include_directories(smoke_test
    PRIVATE
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(test_smoke
    tests/basic_test.cpp
)

target_link_libraries(test_smoke
    PRIVATE
    Qt6::Core
    ${OpenCV_LIBS}
    GTest::gtest_main
)

target_include_directories(test_smoke
    PRIVATE
    ${OpenCV_INCLUDE_DIRS}
)

include(GoogleTest)
gtest_discover_tests(test_smoke)
