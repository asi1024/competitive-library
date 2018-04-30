#!/bin/bash

set -eu

for file in `ls ../cpp/src/*`; do
    base=`basename ${file}`
    echo -n "Compiling ${base} ... "
    python preprocess.py ${file} > tmp.cpp
    g++ --std=c++14 tmp.cpp
    rm tmp.cpp
    echo "ok"
done
