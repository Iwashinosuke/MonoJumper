#!/bin/bash

if [ "$2" != "Debug" ] && [ "$2" != "Release" ] && [ "$2" != "RelWithDebInfo" ] && [ "$2" != "MinSizeRel" ]; then
    echo "Usage: ./build.sh [linux | windows] [Debug | Release | RelWithDebInfo | MinSizeRel]"
    exit 1
fi
if [ "$1" = "linux" ]; then
    cmake -S . -B build-linux \
          -G Ninja \
          -DCMAKE_BUILD_TYPE=$2 \
          -DCMAKE_TOOLCHAIN_FILE=cmake/linux-toolchain.cmake
    cmake --build build-linux

elif [ "$1" = "windows" ]; then
    cmake -S . -B build-windows \
          -G Ninja \
          -DCMAKE_BUILD_TYPE=$2 \
          -DCMAKE_TOOLCHAIN_FILE=cmake/win-toolchain.cmake
    cmake --build build-windows

else
    echo "Usage: ./build.sh [linux | windows] [Debug | Release | RelWithDebInfo | MinSizeRel]"
    exit 1
fi
