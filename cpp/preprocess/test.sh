#!/bin/bash

set -eu

echo "CXX      = $CXX"
echo "CXXFLAGS = $CXXFLAGS"

cd `dirname $0`

for file in `ls ../include/exec/*.cpp`; do
    base=`basename ${file}`
    echo -n "Compiling ${base} ... "
    python preprocess.py ${file} > temp.cpp
    ${CXX} ${CXXFLAGS} -o exec temp.cpp
    rm temp.cpp
    echo "ok"
done

for file in `ls ../src/*`; do
    base=`basename ${file}`
    echo -n "Compiling ${base} ... "
    python preprocess.py ${file} > temp.cpp
    ${CXX} ${CXXFLAGS} -o exec temp.cpp
    rm temp.cpp
    echo "ok"
done
