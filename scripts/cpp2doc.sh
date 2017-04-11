for i in `ls cpp/include/*/* cpp/src/*`
do
    DOC="docs/`dirname $i`/`basename $i .cpp`.md"
    mkdir -p "docs/`dirname $i`"

    echo "## `basename $i`" >  $DOC
    echo ""                 >> $DOC
    echo "\`\`\`cpp"        >> $DOC
    cat $i | sed '/^#pragma/d' | sed '/^#include/d' | sed '/./,$!d' >> $DOC
    echo "\`\`\`"           >> $DOC
    echo ""                 >> $DOC
    echo "- [Back](../)"    >> $DOC
done
