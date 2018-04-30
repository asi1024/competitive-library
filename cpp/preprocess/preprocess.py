#!/usr/bin/env python

import argparse
import os


def preprocess(path):
    includes = set()
    res = []

    def preprocess_line(path, line):
        if line.strip().startswith('#'):
            line = line.strip()
            if line.startswith('#include') and len(line.split('"')) >= 3:
                lx = line.split('"')
                relpath = ''.join(lx[1:len(lx) - 1])
                target_path = os.path.dirname(path) + '/' + relpath
                if target_path.startswith('/'):
                    target_path = target_path[1:]
                preprocess_path(os.path.normpath(target_path))
                return '\n'
            elif line.startswith('#pragma'):
                if ''.join(line.split(' ')[1:]).strip() == 'once':
                    return ''
        return line

    def preprocess_path(path):
        if path not in includes:
            has_not_started = True
            includes.add(path)

            for line in open(path):
                s = preprocess_line(path, line)
                if has_not_started and s.strip() is not "":
                    prefix = '//===== {} =====\n\n'.format(os.path.basename(path))
                    res.append(prefix)
                    has_not_started = False
                res.append(s.rstrip())

    preprocess_path(path)
    print('\n'.join(res))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('filepath', nargs=1, help='cpp file')
    args = parser.parse_args()
    filepath = args.filepath[0]
    preprocess(filepath)
