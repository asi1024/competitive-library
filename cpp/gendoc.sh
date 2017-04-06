#!/bin/bash

set -eu

cd `dirname $0`

echo "| Algorithm | Validated | AOJ Problems |"
echo "|:---------:|:---------:|:-------------|"

for ALGORITHM in `ls include`
do
    LIST=`grep $ALGORITHM src/* | cut -d ':' -f 1 || true`
    VALIDATED='<font color="Red">No</font>'
    AOJLIST=""
    for j in $LIST
    do
        VALIDATED='<font color="ForestGreen">Yes</font>'
        AOJLIST="$AOJLIST$j<br>"
    done
    AOJLIST=`echo $AOJLIST | sed -e 's/<br>$//g'`
    echo "| $ALGORITHM | $VALIDATED | $AOJLIST |"
done
