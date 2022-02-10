cmake_minimum_required(VERSION 3.21)
project(zofia)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(zofia main.cpp)

target_link_libraries(zofia ${CONAN_LIBS})