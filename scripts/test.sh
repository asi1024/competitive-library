#!/bin/bash

set -eux

ulimit -s 32768

DIR=${PWD}
LANG=$1
DIFF=${DIR}/scripts/diff.py
COMPILE='g++-9 --std=gnu++14 -O2 -Wall'

download-aoj () {
    local ID=${1}
    local URL=http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=${ID}
    if [ ! -d ${ID} ]
    then
        oj download --system -s -d ${ID} ${URL} || true
    fi
}

download-yosupo () {
    local ID=${1}
    local URL=https://judge.yosupo.jp/problem/${ID}
    if [ ! -d ${ID} ]
    then
        oj download --system -s -d ${ID} ${URL} || true
    fi
}

mkdir -p ${HOME}/.workspace
pushd ${HOME}/.workspace

# for TEST in `ls ${DIR}/${LANG}/tests/yosupo-range_aff*.cpp`
# for TEST in `ls ${DIR}/${LANG}/tests/aoj-DSL_2_F.cpp`
for TEST in `ls ${DIR}/${LANG}/tests/aoj-2450.cpp`
do
    LABEL=`basename ${TEST} | sed 's/-.*$//'`
    ID=`basename ${TEST} | sed 's/^.*-//' | sed 's/\..*$//'`
    mkdir -p ${LABEL}
    pushd ${LABEL}
    download-${LABEL} ${ID}
    ${COMPILE} ${TEST} -o a.out
    oj test --mle 256 --tle 32 --judge-command ${DIFF} -d ${ID} --gnu-time gtime
    echo ${ID}
    popd
done

popd
