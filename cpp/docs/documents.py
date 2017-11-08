#!/usr/bin/env python

import os


def basename(fname):
    return '.'.join(fname.split('.')[:-1])


def filename(fname):
    return fname.split('/')[-1]


def dirname(fname):
    return '/'.join(fname.split('/')[:-1])


def ignored_line(s):
    return (s.find('#pragma') != -1 or
            (s.find("#include") != -1 and s.find("util.h") != -1))


def page(path, fname):
    filepath = path + "/" + fname
    f = open(filepath, 'r')
    code = f.readlines()
    f.close()

    repo_path = "{{ site.github.repository_url }}/blob/master/%s" % filepath
    includes = [s.split('"')[1] for s in code if s.find('#include') != -1
                and s.find('util.h') == -1 and s.find('"') != -1]

    f = open("docs/" + path + "/" + basename(fname) + ".md", 'a')
    writeln = lambda s: f.write(s + "\n")

    writeln("## " + fname)
    writeln("")
    writeln("- [GitHub](%s)" % repo_path)
    writeln("")
    if includes:
        writeln("### Includes")
        writeln("")
        for name in includes:
            writeln("- [%s](%s)" % (filename(name), basename(name)))
        writeln("")
    writeln("{% highlight cpp %}")

    f2 = open(path + "/" + fname)
    writeln(''.join([s for s in f2.readlines() if not ignored_line(s)]).strip())
    f2.close()

    writeln("{% endhighlight %}")
    writeln("")

    doc_path = path.replace('cpp/', 'cpp/docs/') + "/" + basename(fname) + ".md"
    if os.path.exists(doc_path):
        docf = open(doc_path)
        writeln("".join(docf.readlines()))
        docf.close()

    writeln("[Back](%s)" % os.path.relpath("./", path))
    f.close()


def directory(path):
    for fname in os.listdir(path):
        if os.path.isdir(path + "/" + fname):
            directory(path + "/" + fname)
        else:
            page(path, fname)


if __name__ == '__main__':
    directory('cpp/src')
    directory('cpp/include')
