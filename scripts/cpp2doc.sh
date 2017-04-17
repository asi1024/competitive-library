for i in `ls cpp/include/*/* cpp/src/*`
do
    DOC="docs/`dirname $i`/`basename $i .cpp`.md"
    REPO="{{ site.github.repository_url }}/blob/master/$i"
    TOP="`realpath --relative-to="$i" cpp`"
    mkdir -p "docs/`dirname $i`"

    echo "## `basename $i`"    >  $DOC
    echo ""                    >> $DOC
    echo "- [GitHub]($REPO)"   >> $DOC
    echo ""                    >> $DOC
    echo "{% highlight cpp %}" >> $DOC
    cat $i | sed '/^#pragma/d' | sed '/^#include.*util.h/d' | sed '/./,$!d' >> $DOC
    echo "{% endhighlight %}"  >> $DOC
    echo ""                    >> $DOC
    echo "- [Back]($TOP)"      >> $DOC
done
