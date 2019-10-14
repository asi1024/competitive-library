#!/usr/bin/env python

import collections
import json
import os


max_src_len = 3


def category(path, name, verifier):

    def ext(fname):
        return fname.split('.')[-1]

    def extract_ext(fname):
        return '.'.join(fname.split('.')[:-1])

    def get_relpath(path, start):
        return os.path.normpath(os.path.relpath(path, start))

    def sort_rank(src_name):
        if os.path.dirname(src_name).find('src') != -1:
            return 0
        elif ext(src_name) == 'cpp':
            return 1
        else:
            return 2

    def sort_src(src_list):
        src_with_rank = [(sort_rank(_), _) for _ in src_list]
        src_with_rank.sort()
        return [name for _, name in src_with_rank]

    try:
        files = [f.strip() for f in os.listdir(path)]
        if not files:
            raise os.FileNotFoundError
    except os.FileNotFoundError:
        return

    files_ext = [(0 if ext(f) == 'hpp' else 1, f) for f in files
                 if ext(f) in ('hpp', 'cpp')]
    files_ext.sort()

    print('## ' + name)
    print('')
    print('| Algorithm | Verified | AOJ Problems |')
    print('|:---------:|:--------:|:-------------|')

    for _, fname in files_ext:
        algorithm = '[{}](./{}/{})'.format(
            fname, get_relpath(path, 'cpp'), extract_ext(fname))
        fpath = path + '/' + fname
        if fpath in verifier:
            validated = '<font color="ForestGreen">Yes</font>'
            src_list = ['[{}](./{})'.format(
                os.path.basename(src_path),
                extract_ext(get_relpath(src_path, 'cpp')))
                        for src_path in sort_src(verifier[fpath])]
            if len(src_list) > max_src_len:
                src_str = '<br>'.join(src_list[:max_src_len]) + ' etc...'
            else:
                src_str = '<br>'.join(src_list)
        else:
            validated = '<font color="Red">No</font>'
            src_str = ''
        print('| {} | {} | {} |'.format(algorithm, validated, src_str))

    print('')


def get_verifier_dict():
    memo_set = set()
    res = {}

    def page(path):
        if path in memo_set:
            return
        memo_set.add(path)
        for s in open(path):
            s = s.strip()
            if s.startswith('#include') and s.find('"') != -1:
                relpath = s.split('"')[1]
                key = os.path.normpath(os.path.dirname(path) + '/' + relpath)
                if key not in res:
                    res[key] = []
                res[key].append(path)
                page(key)

    def directory(path):
        for fname in os.listdir(path):
            if os.path.isdir(path + '/' + fname):
                directory(path + '/' + fname)
            elif fname.endswith('.cpp') or fname.endswith('.hpp'):
                page(path + '/' + fname)

    directory('cpp/src')
    return res


if __name__ == '__main__':
    f = open('cpp/include/TITLE.json', 'r')
    print('---')
    print('title: C++')
    print('---')
    decoder = json.JSONDecoder(object_pairs_hook=collections.OrderedDict)
    json = decoder.decode(''.join(f.readlines()))
    verifier_dict = get_verifier_dict()
    f.close()
    for key, value in json.items():
        category('cpp/include/{}'.format(key), value, verifier_dict)
