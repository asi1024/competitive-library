#!/usr/bin/env python

import argparse
from datetime import datetime
from pathlib import Path
import typing


class RuleBase(object):
    def preprocess_line(self, path: Path, recursive) -> typing.List[str]:
        result = [line.rstrip() for line in path.open()]
        return result

    def comment_line(self, line: str) -> str:
        return ''


class CppRule(RuleBase):
    def preprocess_line(self, path: Path, recursive) -> typing.List[str]:
        result = []
        for line in path.open():
            line = line.rstrip()
            if line.startswith('#include') and len(line.split('"')) >= 3:
                relpath = path.parent / ''.join(line.split('"')[1:-1])
                recursive(relpath)
            elif (line.startswith('//') or
                  line.split(' ') == ['#pragma', 'once']):
                continue
            else:
                result.append(line)
        return result

    def comment_line(self, line: str) -> str:
        return '// ' + line


class OCamlRule(RuleBase):
    def preprocess_line(self, path: Path, recursive) -> typing.List[str]:
        result = []
        for line in path.open():
            line = line.rstrip()
            if line.startswith('(*+') and line.endswith('+*)'):
                s = line.split(' ')
                assert (len(s) == 4)
                assert (s[0] == '(*+')
                assert (s[1] == 'import')
                assert (s[3] == '+*)')
                relpath = path.parent / s[2]
                recursive(relpath)
            else:
                result.append(line)
        return result

    def comment_line(self, line: str) -> str:
        return '(* ' + line + ' *)'


class RustRule(RuleBase):
    def preprocess_line(self, path: Path, recursive) -> typing.List[str]:
        result = []
        for line in path.open():
            line = line.rstrip()
            if line.startswith('// #include') and len(line.split('"')) >= 3:
                relpath = path.parent / ''.join(line.split('"')[1:-1])
                recursive(relpath)
            else:
                result.append(line)
        return result

    def comment_line(self, line: str) -> str:
        return '// ' + line


rule_dict: typing.Dict[str, RuleBase] = {
    '.c': CppRule(),
    '.h': CppRule(),
    '.hpp': CppRule(),
    '.cpp': CppRule(),
    '.ml': OCamlRule(),
    '.rs': RustRule(),

    '.cs': RuleBase(),
    '.d': RuleBase(),
    '.go': RuleBase(),
    '.hs': RuleBase(),
    '.java': RuleBase(),
    '.py': RuleBase(),
    '.rb': RuleBase(),
}


def preprocess_file(path: Path) -> str:
    rule: RuleBase = rule_dict[path.suffix]
    includes_set: typing.Set[str] = set()
    result_lines: typing.List[str] = []

    def recursive(path: Path) -> None:
        path = path.resolve()
        if str(path) in includes_set:
            return
        includes_set.add(str(path))

        result = rule.preprocess_line(path, recursive)

        result_lines.append('')
        result_lines.append(rule.comment_line(str(path.name)))
        result_lines.append('')
        result_lines.extend(result)
        result_lines.append('')

    time = datetime.now().strftime("%Y/%m/%d %H:%M:%S")

    result_lines.append(rule.comment_line('===== {} ====='.format(time)))
    recursive(path)
    result_lines.append(rule.comment_line('===== {} ====='.format(time)))

    lines: typing.List[str] = []
    for line in result_lines:
        if not(line == '' and (len(lines) == 0 or lines[-1] == '')):
            lines.append(line)
    return '\n'.join(lines)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('filepath', nargs=1, help='source')
    args = parser.parse_args()
    filepath = Path(args.filepath[0])
    result = preprocess_file(filepath)
    print(result)
