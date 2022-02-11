#!/bin/sh
run() {
    BUILD_TYPE=$1
    if [ -z "$BUILD_TYPE" ]; then
        BUILD_TYPE="debug"
    fi

    C_COMPILER="/usr/bin/clang"
    CPP_COMPILER="/usr/bin/clang++"

    BUILD_TYPE_FORMATTED=$(echo $BUILD_TYPE | tr '[A-Z]' '[a-z]')
    BUILD_DIR=cmake-build-$BUILD_TYPE_FORMATTED

    rm -rf $BUILD_DIR
    mkdir $BUILD_DIR
    cd $BUILD_DIR

    echo "Executing: conan install .. --build=missing"
    conan install .. --build=missing

    echo "Executing: cmake  -G "Unix Makefiles" .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DCMAKE_C_COMPILER=$C_COMPILER -DCMAKE_CXX_COMPILER=$CPP_COMPILER"
    cmake  -G "Unix Makefiles" .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DCMAKE_C_COMPILER=$C_COMPILER -DCMAKE_CXX_COMPILER=$CPP_COMPILER

    echo "Executing: cmake --build ."
    cmake --build .

    cd bin
    ./zofia &
}

run "$1"