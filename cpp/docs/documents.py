#!/usr/bin/env python

import os
from string import Template


def basename(fname):
    return '.'.join(fname.split('.')[:-1])


def filename(fname):
    return fname.split('/')[-1]


def dirname(fname):
    return '/'.join(fname.split('/')[:-1])


def ignored_line(s):
    s = s.strip()
    return (s.startswith('#pragma') or
            (s.startswith("#include") and s.find("util.h") != -1) or
            s.startswith('///'))


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
    code_lines = f.readlines()
    code = ''.join([s for s in code_lines if not ignored_line(s)]).strip()
    f.close()

    repo_path = "{{ site.github.repository_url }}/blob/master/%s" % filepath
    includes = [s.split('"')[1] for s in code_lines if s.find('#include') != -1
                and s.find('util.h') == -1 and s.find('"') != -1]

    f = mkdir_open_write("docs/" + path + "/" + basename(fname) + ".md")
    writeln = lambda s: f.write(s + "\n")

    res = []
    res += ['## {}'.format(fname)]
    res += ['']
    res += ['- [GitHub]({})'.format(repo_path)]
    res += ['']
    if includes:
        res += ['### Includes']
        res += ['']
        for name in includes:
            res += ['- [{}]({})'.format(filename(name), basename(name))]
        res += ['']

    res += ['{% highlight cpp %}']
    res += [code]
    res += ['{% endhighlight %}']
    res += ['']

    doc_path = path.replace('cpp/', 'cpp/docs/') + "/" + basename(fname) + ".md"
    if os.path.exists(doc_path):
        docf = open(doc_path)
        res += ["".join(docf.readlines())]
        docf.close()

    res += ['[Back]({})'.format(os.path.relpath("cpp/", path))]
    writeln('\n'.join(res))
    f.close()


def directory(path):
    for fname in os.listdir(path):
        if os.path.isdir(path + '/'+ fname):
            directory(path + '/' + fname)
        else:
            page(path, fname)


if __name__ == '__main__':
    directory('cpp/src')
    directory('cpp/include')
