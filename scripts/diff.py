#!/usr/bin/env python

import argparse
from pathlib import Path
import typing


checker_type = typing.Callable[[str, str], None]


def is_float(s: str) -> bool:
    if s.lower().endswith('inf') or s.lower().endswith('nan'):
        return False
    try:
        float(s)
    except ValueError:
        return False
    return True


def check_same_word(s1: str, s2: str) -> None:
    s1 = s1.rstrip('\r\n')
    s2 = s2.rstrip('\r\n')
    if is_float(s1) and is_float(s2):
        e, a = float(s1), float(s2)
        if abs(e - a) < (abs(e) + 1) * 1e-6:
            return
    elif s1 == s2:
        return
    raise ValueError('Expected: {}, Actual: {}'.format(s1, s2))


def check_same_recursive(checker: checker_type, delim: str) -> checker_type:
    def wrapper(line1: str, line2: str) -> None:
        s1_list = line1.rstrip('\r\n').split(delim)
        s2_list = line2.rstrip('\r\n').split(delim)

        if len(s1_list) != len(s2_list):
            raise ValueError('Not same langth')
        for s1, s2 in zip(s1_list, s2_list):
            checker(s1, s2)

    return wrapper


def read_file(path: Path) -> str:
    with path.open() as f:
        s = '\n'.join(f.readlines())
    return s


def diff(path1: Path, path2: Path) -> None:
    s1 = read_file(path1)
    s2 = read_file(path2)
    check_same_line = check_same_recursive(check_same_word, ' ')
    check_same_lines = check_same_recursive(check_same_line, '\n')
    check_same_lines(s1, s2)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='diff')
    parser.add_argument('input', type=str, nargs=1, help='Path to FILE')
    parser.add_argument('your_output', type=str, nargs=1, help='Path to FILE')
    parser.add_argument('expected_output', type=str, nargs=1, help='Path to FILE')
    args = parser.parse_args()

    path1 = Path(args.your_output[0])
    path2 = Path(args.expected_output[0])

    diff(path1, path2)
