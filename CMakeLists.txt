cmake_minimum_required(VERSION 3.21)
project(zofia)

set(CMAKE_CXX_STANDARD 11)

#Specific 32 or 64 system
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    # 64 bits
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
endif()

#Specific compiler options - set C++11 flag for g++ and clang
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    # Mac OS X: clang uses libc++ standard library
    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    endif ()
endif ()
message(STATUS "Compiler ${CMAKE_CXX_COMPILER_ID} compile with Flags: ${CMAKE_CXX_FLAGS}")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#####################################################################################################################################
#### Internal api #####
set(GAME_SOURCE
        core/Application.cpp
        core/Game.cpp
        core/Greeting.cpp
        core/Size.cpp

        core/config/Config.cpp
        core/config/Constant.cpp

        core/logging/BaseLogger.cpp
        core/logging/Logger.cpp


        game-states/BaseState.cpp
        game-states/ExampleState.cpp
        game-states/StateFactory.cpp
        game-states/StateManager.cpp

        game-states/intro/IntroState.cpp

        entities/Entity.cpp
        entities/Rectangle.cpp
        entities/Typography.cpp
        entities/EntityContext.cpp core/Position.cpp)

set(GAME_HEADER
        core/config/config.hpp

        core/core.hpp

        core/logging/logging.hpp

        entities/base.hpp
        entities/full.hpp

        game-states/base.hpp
        game-states/intro/intro.hpp
        game-states/menu/menu.hpp)
#
set(all_code_files
        ${GAME_HEADER}
        ${GAME_SOURCE})

add_library(${APP_NAME} SHARED ${all_code_files})

add_executable(zofia main.cpp)

target_link_libraries(zofia ${CONAN_LIBS})

#### Copy Resources #####
add_custom_command(TARGET zofia PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/static $<TARGET_FILE_DIR:zofia>)