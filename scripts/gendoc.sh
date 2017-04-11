#!/bin/bash

set -eu

LANGUAGE=$1

cd $2

echo ""
echo "# $LANGUAGE"
echo ""

DIR="{{ site.github.repository_url }}/blob/master/$2"

cat include/TITLE | while read i
do
    CATEGORY=`echo $i | cut -d ' ' -f 1`
    TITLE=`echo $i | cut -d ' ' -f 2- | sed -e 's/-/ /g'`
    if [ -d "include/$CATEGORY" ]; then
        if [ "`ls include/$CATEGORY`" = "" ]; then
            continue
        fi
        echo "## $TITLE"
        echo ""
        echo "| Algorithm | Verified | AOJ Problems |"
        echo "|:---------:|:--------:|:------------:|"
        for ALGORITHM in `ls include/$CATEGORY`
        do
            LIST=`grep -r $ALGORITHM src | cut -d ':' -f 1 || true`
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
