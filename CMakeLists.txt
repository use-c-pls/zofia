cmake_minimum_required(VERSION 3.21)
project(zofia)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Specific compiler options - set C++11 flag for g++ and clang
if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

    # Mac OS X: clang uses libc++ standard library
    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    endif ()
endif ()

#####################################################################################################################################
#### Internal api #####
set(GAME_SOURCE)
set(GAME_HEADER)

list(APPEND GAME_SOURCE
        core/hello.cpp
        )
list(APPEND GAME_HEADER
        core/hello.h
        )
#
set(all_code_files
        ${GAME_HEADER}
        ${GAME_SOURCE}
        )
add_library(${APP_NAME} SHARED ${all_code_files})

add_executable(zofia main.cpp)

target_link_libraries(zofia ${CONAN_LIBS})

#### Copy Resources #####
add_custom_command(TARGET zofia PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/static $<TARGET_FILE_DIR:zofia>)