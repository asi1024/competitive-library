#!/bin/bash

set -eux

# Install `competitive-library` to use preprocessor.
# $ pip install git+https://github.com/asi1024/competitive-library.git

preprocessor sample.cpp | tee combined.cpp
g++ --std=c++14 -O2 combined.cpp -o a.out
