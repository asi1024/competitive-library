#!/bin/bash

set -eu

cd `dirname $0`

LANGUAGE=$1
# DIR=$2

echo ""
echo "# $LANGUAGE"
echo ""

DIR="{{ site.github.repository_url }}/blob/master/cpp"

cat include/TITLE | while read i
do
    CATEGORY=`echo $i | cut -d ' ' -f 1`
    TITLE=`echo $i | cut -d ' ' -f 2- | sed -e 's/-/ /g'`
    if [ -d "include/$CATEGORY" ]; then
        echo "## $TITLE"
        echo ""
        echo "| Algorithm | Verified | AOJ Problems |"
        echo "|:---------:|:--------:|:------------:|"
        for ALGORITHM in `ls include/$CATEGORY`
        do
            LIST=`grep $ALGORITHM src/* | cut -d ':' -f 1 || true`
            ALGORITHM="[$ALGORITHM]($DIR/include/$CATEGORY/$ALGORITHM)"
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
    fi
done
