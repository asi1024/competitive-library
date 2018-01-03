#!/usr/bin/env python

import argparse
import os
import re


def expand(fname, parent_files):
    if fname in parent_files:
        raise Exception('circular dependency')
    source = open(fname, 'r')
    res = ""
    for line in source:
        match = re.fullmatch('\(\*\+\s*import\s+([^\s]*)\s*\+\*\)\n', line)
        if match:
            child = match.group(1)
            res += expand(child, parent_files + [fname])
        else:
            res += line
    source.close()
    return res


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='preprocess')
    parser.add_argument('source_file', type=str, nargs=1, help='Path to FILE')
    args = parser.parse_args()
    res = expand(args.source_file[0], [])
    print(res)
