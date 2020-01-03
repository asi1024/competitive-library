#!/bin/bash

set -eux

ulimit -s 32768

DIR=${PWD}
LANG=$1
DIFF=${DIR}/scripts/diff.py

download () {
    local ID=${1}
    local URL=http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=${ID}
    if [ ! -d ${ID} ]
    then
        oj download --system -s -d ${ID} ${URL} || true
    fi
}

mkdir -p ${HOME}/.workspace
pushd ${HOME}/.workspace

mkdir -p aoj
pushd aoj

for TEST in `ls ${DIR}/${LANG}/src/*.cpp`
do
    ID=`basename ${TEST} | sed 's/\..*$//'`
    download ${ID}
    ${COMPILE} ${TEST} -o a.out
    oj test --mle 256 --tle 32 --judge-command ${DIFF} -d ${ID}
    echo ${ID}
done

popd
popd
