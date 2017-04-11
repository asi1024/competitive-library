for i in `ls cpp/include/*/* cpp/src/*`
do
    DOC="docs/`dirname $i`/`basename $i .cpp`.md"
    REPO="{{ site.github.repository_url }}/bolb/master/$i"
    TOP="https://{{ site.github.owner_name }}.github.io/competitive-library"
    mkdir -p "docs/`dirname $i`"

    echo "## `basename $i`"  >  $DOC
    echo ""                  >> $DOC
    echo "- [GitHub]($REPO)" >> $DOC
    echo ""                  >> $DOC
    echo "\`\`\`cpp"         >> $DOC
    cat $i | sed '/^#pragma/d' | sed '/^#include/d' | sed '/./,$!d' >> $DOC
    echo "\`\`\`"            >> $DOC
    echo ""                  >> $DOC
    echo "- [Back]($TOP)"    >> $DOC
done
