import argparse
import itertools
import sys

parser = argparse.ArgumentParser(description='diff')
parser.add_argument('file1', type=str, nargs=1, help='Path to FILE')
parser.add_argument('file2', type=str, nargs=1, help='Path to FILE')

args = parser.parse_args()

f1 = open(args.file1[0], 'r')
f2 = open(args.file2[0], 'r')

def is_float(s):
    if s == 'inf' or s == 'INF':
        return False
    try:
        float(s)
    except ValueError:
        return False
    return True

def is_same(s, t):
    if is_float(s) and is_float(t):
        return abs(float(s) - float(t)) < 1e-8
    return s == t

def is_ok(s1, s2):
    if len(s1) != len(s2):
        return False
    for s, t in zip(s1, s2):
        s = s.split(' ')
        t = t.split(' ')
        if len(s) != len(t):
            return False
        for i, j in zip(s, t):
            if not is_same(i, j):
                return False
    return True

s1 = [s.rstrip('\r\n') for s in f1]
s2 = [s.rstrip('\r\n') for s in f2]

if not is_ok(s1, s2):
    sys.exit(1)
