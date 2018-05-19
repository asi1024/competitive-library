#!/usr/bin/env python

import argparse
from datetime import datetime
import os


def preprocess(path):
    includes_set = set()
    includes_list = []

    def get_includes_list(path):
        if path in includes_set:
            return
        includes_set.add(path)
        for line in open(path):
            line = line.strip()
            if line.startswith('#include') and len(line.split('"')) >= 3:
                relpath = ''.join(line.split('"')[1:-1])
                target_path = os.path.dirname(path) + '/' + relpath
                if target_path.startswith('/'):
                    target_path = target_path[1:]
                get_includes_list(os.path.normpath(target_path))
        includes_list.append(path)

    def ignore_line(line):
        line = line.strip()
        return (line.startswith('//') or
                (line.startswith('#include') and len(line.split('"')) >= 3) or
                line.split(' ') == ['#pragma', 'once'])

    get_includes_list(path)
    time = datetime.now().strftime("%Y/%m/%d %H:%M:%S")

    code_list = []

    code_list.append('// ===== {} ====='.format(time))

    for path in includes_list:
        code_list.append('')
        code_list.append('// {}'.format(path))
        code_list.append('')
        code_list += [_ for _ in open(path) if not ignore_line(_)]

    code_list.append('// ===== {} ====='.format(time))

    res = ''
    for s, prev in zip(code_list, [''] + code_list):
        if s.strip() != '' or prev.strip() != '':
            res += s.rstrip() + '\n'

    return res


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('filepath', nargs=1, help='cpp file')
    args = parser.parse_args()
    filepath = args.filepath[0]
    print(preprocess(filepath))
