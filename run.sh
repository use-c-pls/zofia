#!/bin/sh
run() {
    BUILD_TYPE=$1
    if [ -z "$BUILD_TYPE" ]; then
        BUILD_TYPE="debug"
    fi

    C_COMPILER=/usr/bin/gcc-11
    CPP_COMPILER=/usr/bin/g++-11

    BUILD_TYPE_FORMATTED=$(echo $BUILD_TYPE | tr '[A-Z]' '[a-z]')
    BUILD_DIR=cmake-build-$BUILD_TYPE_FORMATTED

    rm -rf $BUILD_DIR
    mkdir $BUILD_DIR
    cd $BUILD_DIR

    conan install .. --build=missing
    cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DCMAKE_C_COMPILER=$C_COMPILER -DCMAKE_CXX_COMPILER=$CPP_COMPILER
    cmake --build .
#
    bin/zofia
}

run "$1"