#!/usr/bin/env python

import os


def ext(fname):
    return fname.split('.')[-1]


def basename(fname):
    return '.'.join(fname.split('.')[:-1])


def filename(fname):
    return fname.split('/')[-1]


def dirname(fname):
    return '/'.join(fname.split('/')[:-1])


def ignored_line(s):
    s = s.strip()
    return (s.startswith('#pragma') or
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
    includes = [s.split('"')[1] for s in code_lines
                if s.strip().startswith('#include') and s.find('"') != -1]

    dirname = os.path.dirname(__file__)
    xmlname = basename(fname).replace('_', '__')
    xmlpath = dirname + '/xml/' + xmlname + '_8' + ext(fname) + '.xml'

    res = '---\n'
    res += 'title: "' + filename(fname) + '"\n'
    res += '---\n\n'
    res += '- [GitHub]({})\n\n'.format(repo_path)

    res += '{% highlight cpp %}\n'
    res += code + '\n'
    res += '{% endhighlight %}\n\n'

    if includes:
        res += '### Includes\n\n'
        res += ''.join('- [{}]({})\n'.format(filename(name), basename(name))
                       for name in includes)
        res += '\n'

    res += '[Back]({})\n'.format(os.path.relpath('cpp/', path))

    f = mkdir_open_write('docs/' + path + '/' + basename(fname) + '.md')
    f.write(res)
    f.close()


def directory(path):
    for fname in os.listdir(path):
        if os.path.isdir(path + '/' + fname):
            directory(path + '/' + fname)
        elif fname.endswith('.cpp') or fname.endswith('.hpp'):
            page(path, fname)


if __name__ == '__main__':
    directory('cpp/tests')
    directory('cpp/include')
