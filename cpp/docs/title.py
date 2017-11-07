#!/usr/bin/env python

import collections
import json
import os


def category(path, name, verifier):

    def basename(fname):
        return '.'.join(fname.split('.')[:-1])

    try:
        path = "cpp/include/%s" % path
        files = os.listdir(path)
        if not files:
            raise os.FileNotFoundError
    except os.FileNotFoundError:
        return

    files.sort()

    print("##", name)
    print()
    print("| Algorithm | Verified | AOJ Problems |")
    print("|:---------:|:--------:|:------------:|")

    for fname in files:
        algorithm = "[%s](./%s/%s)" % (fname, path, basename(fname))
        if fname in verifier:
            validated = '<font color="ForestGreen">Yes</font>'
            aojlist = ["[%s](./cpp/src/%s)" % (vname, basename(vname))
                       for vname in verifier[fname]]
            aojlist = '<br>'.join(aojlist)
        else:
            validated = '<font color="Red">No</font>'
            aojlist = ''
        print("| %s | %s | %s |" % (algorithm, validated, aojlist))

    print()


def verifier_dict():
    path = "cpp/src"
    files = os.listdir(path)
    res = {}

    files.sort()

    for fname in files:
        f = open(path + "/" + fname)
        includes = [s for s in f.readlines()
                    if s.find('#include') != -1 and s.find('"') != -1]
        f.close()
        for s in includes:
            key = s.split('"')[1].split('/')[-1]
            if key not in res:
                res[key] = [fname]
            else:
                res[key].append(fname)

    return res


if __name__ == '__main__':
    f = open("cpp/include/TITLE.json", 'r')
    print("\n# C++\n")
    decoder = json.JSONDecoder(object_pairs_hook=collections.OrderedDict)
    json = decoder.decode(''.join(f.readlines()))
    f.close()
    for key, value in json.items():
        category(key, value, verifier_dict())
