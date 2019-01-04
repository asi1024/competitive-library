#!/bin/bash

set -eu

TEST='src'
WORKSPACE='.workspace'

cd `dirname $0`

mkdir -p ${WORKSPACE}
for t in `ls ${TEST}/$@`
do
    b=`basename ${t}`
    ./preprocess.py ${TEST}/${b} > ${WORKSPACE}/${b}
done

red-baron .workspace/$@
