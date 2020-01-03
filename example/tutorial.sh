#!/bin/bash

set -eux

pip install -U pip
pip install git+https://github.com/asi1024/competitive-library.git
preprocessor sample.cpp > combined.cpp
g++ --std=c++14 -O2 combined.cpp -o a.out
