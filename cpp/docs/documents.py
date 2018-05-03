#!/usr/bin/env python

import os


def basename(fname):
    return '.'.join(fname.split('.')[:-1])


def filename(fname):
    return fname.split('/')[-1]


def dirname(fname):
    return '/'.join(fname.split('/')[:-1])


def ignored_line(s):
    s = s.strip()
    return (s.startswith('#pragma') or
            (s.startswith('#include') and s.find('util.h') != -1) or
            s.startswith('///'))


def mkdir_open_write(path):
    path_list = path.split('/')
    for i, _ in enumerate(path_list):
        dirpath = '/'.join(path_list[:i])
        if dirpath and not os.path.exists(dirpath):
            os.mkdir(dirpath)
    return open(path, 'w')


def page(path, fname):
    filepath = path + '/' + fname
    f = open(filepath, 'r')
    code_lines = f.readlines()
    code = ''.join([s for s in code_lines if not ignored_line(s)]).strip()
    f.close()

    repo_path = '{{ site.github.repository_url }}/blob/master/%s' % filepath
    includes = [s.split('"')[1] for s in code_lines if s.find('#include') != -1
                and s.find('util.h') == -1 and s.find('"') != -1]

    res = []

    res += ['## {}\n'.format(fname)]
    res += ['- [GitHub]({})\n'.format(repo_path)]
    if includes:
        res += ['### Includes\n']
        res += [''.join('- [{}]({})\n'.format(filename(name), basename(name))
                        for name in includes)]

    res += ['{% highlight cpp %}']
    res += [code]
    res += ['{% endhighlight %}\n']

    doc_path = path.replace('cpp/', 'cpp/docs/') + '/' + basename(fname) + '.md'
    if os.path.exists(doc_path):
        docf = open(doc_path)
        res += [''.join(docf.readlines())]
        docf.close()

    res += ['[Back]({})'.format(os.path.relpath('cpp/', path))]

    f = mkdir_open_write('docs/' + path + '/' + basename(fname) + '.md')
    f.write('\n'.join(res) + '\n')
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
