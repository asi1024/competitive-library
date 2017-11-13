#!/bin/bash

set -eu

echo "CXX      = $CXX"
echo "CXXFLAGS = $CXXFLAGS"

function compile() {
    $CXX $CXXFLAGS -o exec $1
}

TESTSUITES="../testsuites"
TIMELIMIT=8

cd `dirname $0`

BUILD_ONLY=0

for j in $@
do
    if [ $j == "--build-only" ]; then
        BUILD_ONLY=1
    fi
done

for i in `ls src/*.cpp`
do
    FILENAME=`basename $i .cpp`
    PROBLEM_ID=`echo $FILENAME | tr '.' '\n' | head -n 1`
    FLAG=0

    for j in $@
    do
        if [ $j == $FILENAME ] || [ $j == "--all" ] || [ $j == "-all" ]; then
            FLAG=1
        fi
    done
    if [ $FLAG == 0 ]; then
        continue
    fi

    # compile
    echo -e "Compiling ${FILENAME}.cpp ...\r\c"
    compile $i
    echo -e "Compiling ${FILENAME}.cpp done."
    if [ $BUILD_ONLY == 1 ]; then
        continue
    fi

    # download
    $TESTSUITES/aoj.sh $PROBLEM_ID

    # run
    MAX_TIME="0.00"
    for j in `ls -v $TESTSUITES/$PROBLEM_ID/*.in`
    do
        TESTCASE=`basename $j .in`
        echo -e "$FILENAME: $TESTCASE.in\r\c"
        TIMEFORMAT=%R
        LOG=`(time timeout -s 9 $TIMELIMIT ./exec < $j > out 2> log) 2>&1` || (
            LOG=`echo $LOG | tail -n 1`
            TIME=${LOG##* }
            echo ""
            if [ `echo "$TIME > 1" | bc -l` == 1 ]; then
                echo "time: $TIME sec"
                echo -e "$FILENAME: \033[0;33mtime limit exceeded\033[0m in #$TESTCASE."
            else
                echo "===== error ====="
                cat log
                echo "time: $TIME sec"
                echo -e "$FILENAME: \033[0;35mruntime error\033[0m in #$TESTCASE."
            fi
            rm -f exec out log
            exit 1)
        LOG=`echo $LOG | tail -n 1`
        TIME=${LOG##* }
        if [ `echo "$TIME > $MAX_TIME" | bc -l` == 1 ]; then
            MAX_TIME=$TIME
        fi
        python $TESTSUITES/diff.py out "`dirname $j`/$TESTCASE.out" || (
            echo ""
            echo "time: $TIME sec"
            echo -e "$FILENAME: \033[0;31mwrong answer\033[0m in #$TESTCASE."
            rm -f exec out log
            exit 1)
    done
    echo -e "$FILENAME: \033[0;32mpassed\033[0m (time: $MAX_TIME sec)."
done

rm -f exec out log
