#!/bin/bash

set -eu

OCAMLFIND='ocamlfind'
OCAMLOPT='ocamlopt'
OCAMLFLAGS='-linkpkg -thread -package str,num,threads,batteries'

SUFFIX=".ml"

function compile() {
    mkdir -p workspace
    ./preprocess.py $1 > workspace/main.ml
    ${OCAMLFIND} ${OCAMLOPT} -o exec workspace/main.ml ${OCAMLFLAGS}
}

TESTSUITES="../testsuites"
TIMELIMIT=8

cd `dirname $0`

BUILD_ONLY=0

for FLAG in $@
do
    if [ ${FLAG} == "--build-only" ]; then
        BUILD_ONLY=1
    fi
done

for FILEPATH in `ls src/*${SUFFIX}`
do
    FILENAME=`basename ${FILEPATH} ${SUFFIX}`
    PROBLEM_ID=`echo ${FILENAME} | tr '.' '\n' | head -n 1`
    CHECK=0

    for FLAG in $@
    do
        if [ ${FLAG} == $FILENAME ] || [ ${FLAG} == "--all" ] || [ ${FLAG} == "-all" ]; then
            CHECK=1
        fi
    done
    if [ ${CHECK} == 0 ]; then
        continue
    fi

    # compile
    echo -e "Compiling ${FILENAME}${SUFFIX} ...\r\c"
    compile ${FILEPATH}
    echo -e "Compiling ${FILENAME}${SUFFIX} done."
    if [ ${BUILD_ONLY} == 1 ]; then
        continue
    fi

    # download
    ${TESTSUITES}/aoj.sh ${PROBLEM_ID}

    # run
    MAX_TIME="0.00"
    for TESTPATH in `ls -v ${TESTSUITES}/${PROBLEM_ID}/*.in`
    do
        TESTCASE=`basename ${TESTPATH} .in`
        echo -e "${FILENAME}: ${TESTCASE}.in\r\c"
        TIMEFORMAT=%R
        LOG=`(time timeout -s 9 ${TIMELIMIT} ./exec < ${TESTPATH} > out 2> log) 2>&1` || (
            LOG=`echo ${LOG} | tail -n 1`
            TIME=${LOG##* }
            echo ""
            if [ `echo "${TIME} > 1" | bc -l` == 1 ]; then
                echo "time: ${TIME} sec"
                echo -e "${FILENAME}: \033[0;33mtime limit exceeded\033[0m in #${TESTCASE}."
            else
                echo "===== error ====="
                cat log
                echo "time: ${TIME} sec"
                echo -e "${FILENAME}: \033[0;35mruntime error\033[0m in #${TESTCASE}."
            fi
            rm -rf exec out log workspace
            exit 1)
        LOG=`echo ${LOG} | tail -n 1`
        TIME=${LOG##* }
        if [ `echo "${TIME} > ${MAX_TIME}" | bc -l` == 1 ]; then
            MAX_TIME=${TIME}
        fi
        python ${TESTSUITES}/diff.py out "`dirname ${TESTPATH}`/${TESTCASE}.out" || (
            echo ""
            echo "time: ${TIME} sec"
            echo -e "${FILENAME}: \033[0;31mwrong answer\033[0m in #${TESTCASE}."
            rm -rf exec out log workspace
            exit 1)
    done
    echo -e "${FILENAME}: \033[0;32mpassed\033[0m (time: ${MAX_TIME} sec)."
done

rm -rf exec out log workspace
