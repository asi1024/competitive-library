#!/bin/bash

set -eu

cd `dirname $0`

echo ""
echo "## C++"
echo ""
echo "| Algorithm | Validated | AOJ Problems |"
echo "|:---------:|:---------:|:------------:|"

DIR="https://github.com/asi1024/competitive-library/blob/master/cpp"

for ALGORITHM in `ls include`
do
    LIST=`grep $ALGORITHM src/* | cut -d ':' -f 1 || true`
    ALGORITHM="[$ALGORITHM]($DIR/include/$ALGORITHM)"
    VALIDATED='<font color="Red">No</font>'
    AOJLIST=""
    for j in $LIST
    do
        VALIDATED='<font color="ForestGreen">Yes</font>'
        AOJLIST="$AOJLIST[`basename $j`]($DIR/$j)<br>"
    done
    AOJLIST=`echo $AOJLIST | sed -e 's/<br>$//g'`
    echo "| $ALGORITHM | $VALIDATED | $AOJLIST |"
done

echo ""
