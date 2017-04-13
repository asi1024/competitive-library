#!/bin/bash

if [ $# != 1 ]; then
    echo "Usage: $0 [PROBLEM_ID]" >&2
    exit 1
fi

HOST=http://analytic.u-aizu.ac.jp
PORT=8080
URL=$HOST:$PORT/aoj/testcase.jsp
PROBLEM_ID=$1

cd `dirname $0`
mkdir -p $PROBLEM_ID
cd $PROBLEM_ID

if [ -f CONFIG ]; then
    echo -e "$PROBLEM_ID is already downloaded."
    exit 0
fi

wget "$URL?id=$PROBLEM_ID&case=??&type=in"  -o /dev/null -O /dev/null

if [ $? == 0 ]; then
    echo "in preparation" >&2
    exit 1
fi

for i in `seq 1 1000`
do
    wget "$URL?id=$PROBLEM_ID&case=$i&type=in"  -o /dev/null -O $i.in
    wget "$URL?id=$PROBLEM_ID&case=$i&type=out" -o /dev/null -O $i.out
    if [ $? != 0 ]; then
        rm $i.in $i.out
        echo -e "$PROBLEM_ID is downloaded."
        echo $i > CONFIG
        exit 0
    fi
    echo -e "$PROBLEM_ID #$i\r\c"
done

exit 1
