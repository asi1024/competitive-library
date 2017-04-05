#!/bin/bash

set -eu

if [ -z ${CXX+x} ]; then
    exit 0
fi

TARGET=exec
TESTSUITES="../testsuites"

cd `dirname $0`

for i in `ls src/*.cpp`
do
    PROBLEM_ID=`basename $i .cpp`
    $TESTSUITES/aoj.sh $PROBLEM_ID
    echo -e "Compiling $PROBLEM_ID.cpp ...\r\c"
    $CXX $CXXFLAGS -o $TARGET $i
    echo -e "Compiling $PROBLEM_ID.cpp done."
    MAX_TIME="0.00"
    for j in `ls -v $TESTSUITES/$PROBLEM_ID/*.in`
    do
        TESTCASE=`basename $j .in`
        echo -e "$PROBLEM_ID: $TESTCASE.in\r\c"
        TIMEFORMAT=%R
        LOG=`(time timeout -s 9 1 ./$TARGET < $j > out 2> log) 2>&1` || (
            LOG=`echo $LOG | tail -n 1`
            TIME=${LOG##* }
            echo ""
            if [ `echo "$TIME > 1" | bc -l` == 1 ]; then
                echo "time: $TIME sec"
                echo -e "$PROBLEM_ID: \033[0;33mtime limit exceeded\033[0m in #$TESTCASE."
            else
                echo "===== error ====="
                cat log
                echo "time: $TIME sec"
                echo -e "$PROBLEM_ID: \033[0;35mruntime error\033[0m in #$TESTCASE."
            fi
            rm exec
            rm out
            rm log
            exit 1)
        LOG=`echo $LOG | tail -n 1`
        TIME=${LOG##* }
        if [ `echo "$TIME > $MAX_TIME" | bc -l` == 1 ]; then
            MAX_TIME=$TIME
        fi
        python $TESTSUITES/diff.py out "`dirname $j`/$TESTCASE.out" || (
            echo ""
            echo "time: $TIME sec"
            echo -e "$PROBLEM_ID: \033[0;31mwrong answer\033[0m in #$TESTCASE."
            rm exec
            rm out
            rm log
            exit 1)
    done
    echo -e "$PROBLEM_ID: \033[0;32mpassed\033[0m (time: $MAX_TIME sec)."
done

rm exec
rm out
rm log
