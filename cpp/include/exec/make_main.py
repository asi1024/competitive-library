#!/usr/bin/env python

import collections
import json
import os


if __name__ == '__main__':
    f = open('cpp/include/TITLE.json', 'r')
    decoder = json.JSONDecoder(object_pairs_hook=collections.OrderedDict)
    json = decoder.decode(''.join(f.readlines()))
    f.close()

    res = ''
    for key, value in json.items():
        path = 'cpp/include/{}'.format(key)
        res += '// {}\n'.format(value)
        for filename in os.listdir(path):
            res += '#include "../{}/{}"\n'.format(key, filename)
        res += '\n'

    res += 'int main() { return 0; }\n'
    print(res.strip())
