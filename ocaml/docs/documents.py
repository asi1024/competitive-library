#!/usr/bin/env python

import os
import re


regex = re.compile('\(\*\+\s*import\s+([^\s]*)\s*\+\*\)\n')


def basename(fname):
    return '.'.join(fname.split('.')[:-1])


def filename(fname):
    return fname.split('/')[-1]


def dirname(fname):
    return '/'.join(fname.split('/')[:-1])


def ignored_line(s):
    return (s.find('(*+') != -1 and s.find("+*)") != -1)


def mkdir_open_write(path):
    path_list = path.split('/')
    for i, _ in enumerate(path_list):
        dirpath = "/".join(path_list[:i])
        if dirpath and not os.path.exists(dirpath):
            os.mkdir(dirpath)
    return open(path, 'w')


def page(path, fname):
    filepath = path + "/" + fname
    f = open(filepath, 'r')
    code = f.readlines()
    f.close()

    repo_path = "{{ site.github.repository_url }}/blob/master/%s" % filepath
    includes = [os.path.relpath("ocaml/" + regex.fullmatch(s).group(1), path)
                for s in code if ignored_line(s)]

    f = mkdir_open_write("docs/" + path + "/" + basename(fname) + ".md")
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
    writeln("{% highlight ocaml %}")

    f2 = open(path + "/" + fname)
    writeln(''.join([s for s in f2.readlines() if not ignored_line(s)]).strip())
    f2.close()

    writeln("{% endhighlight %}")
    writeln("")

    doc_path = path.replace('ocaml/', 'ocaml/docs/') + "/" + basename(fname) + ".md"
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
    directory('ocaml/src')
    directory('ocaml/include')
