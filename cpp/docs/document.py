#!/usr/bin/env python

import os


def page(path, fname):
    f = open(path + "/" + fname)
    code = f.readlines()
    includes = [s for s in f.readlines() if s.find('#include') != -1]


def directory(path):
    for fname in os.listdir(path):
        page(path, fname)


if __name__ == '__main__':
    directory('cpp/src')
    directory('cpp/include)
