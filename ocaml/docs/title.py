#!/usr/bin/env python

import collections
import json
import os
import re


def category(path, name, verifier):

    def basename(fname):
        return '.'.join(fname.split('.')[:-1])

    try:
        path = "include/%s" % path
        files = os.listdir("ocaml/" + path)
        if not files:
            raise os.FileNotFoundError
    except os.FileNotFoundError:
        return

    files.sort()

    print("## " + name)
    print("")
    print("| Algorithm | Verified | AOJ Problems |")
    print("|:---------:|:--------:|:------------:|")

    for fname in files:
        algorithm = "[%s](./%s/%s)" % (fname, path, basename(fname))
        if fname in verifier:
            validated = '<font color="ForestGreen">Yes</font>'
            aojlist = ["[%s](./src/%s)" % (vname, basename(vname))
                       for vname in verifier[fname]]
            aojlist = '<br>'.join(aojlist)
        else:
            validated = '<font color="Red">No</font>'
            aojlist = ''
        print("| %s | %s | %s |" % (algorithm, validated, aojlist))

    print("")


def verifier_dict():
    path = "ocaml/src"
    regex = re.compile('\(\*\+\s*import\s+([^\s]*)\s*\+\*\)\n')
    files = os.listdir(path)
    res = {}

    files.sort()

    for fname in files:
        f = open(path + "/" + fname)
        for s in f:
            m = regex.fullmatch(s)
            if m:
                key = m.group(1).split('/')[-1]
                if key not in res:
                    res[key] = [fname]
                else:
                    res[key].append(fname)
        f.close()

    return res


if __name__ == '__main__':
    f = open("ocaml/include/TITLE.json", 'r')
    print("\n# OCaml\n")
    decoder = json.JSONDecoder(object_pairs_hook=collections.OrderedDict)
    json = decoder.decode(''.join(f.readlines()))
    f.close()
    for key, value in json.items():
        category(key, value, verifier_dict())
