cmake_minimum_required(VERSION 3.16)
project(Test1_Client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(OpenCV REQUIRED)

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
