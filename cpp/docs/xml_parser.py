#!/usr/bin/env python

import argparse
import os
import re
import xml.etree.ElementTree as ET


def get_typedef(node):
    return [elem for elem in node.findall('./*/*/memberdef')
            if elem.attrib['kind'] == 'typedef']

def tostring(node):
    return re.sub('<.*?>', '', ET.tostring(node).decode('utf-8').strip())

def filter_kind(nodes, tag):
    x = [node for node in nodes if node.attrib['kind'] == tag]
    return x[0] if x else None


def class_doc(node):
    name = node.find('compoundname').text

    res = ''
    res += '## {}\n\n'.format(name)

    sections = node.findall('sectiondef')
    public_funcs = filter_kind(sections, 'public-func')

    if public_funcs:
        public_funcs = public_funcs.findall('memberdef')
        fnames = set()

        for elem in public_funcs:
            fname = elem.find('name').text
            if fname == name:
                fname = '(constructor)'
            elif fname == '~' + name:
                fname = '(destructor)'
            fnames.add(fname)

        fnames = sorted(list(fnames))
        res += '### Member functions\n\n'

        for fname in fnames:
            res += '#### {}\n'.format(fname)
            if fname == '(constructor)':
                fname = name
            elif fname == '(destructor)':
                fname = '~' + name
            nodes = [_ for _ in public_funcs if _.find('name').text == fname]
            for elem in nodes:
                res += '{% highlight cpp %}\n'
                typestr = elem.find('type').text
                res += typestr + ' ' if typestr else ''
                res += elem.find('name').text
                res += elem.find('argsstring').text + ';\n'
                res += '{% endhighlight %}\n\n'

                brief = elem.find('briefdescription/para')
                if brief is not None:
                    res += '- {}\n'.format(brief.text)
                sects = elem.findall('detaileddescription/para/simplesect')
                complexity = filter_kind(sects, 'post')
                if complexity is not None:
                    complexity_text = complexity.find('para').text
                    res += '- Complexity: {}\n'.format(complexity_text)
            res += '\n'

    return res


def function_doc(node):
    res = ''
    res += '## {}\n\n'.format(node.find('name').text)

    res += '{% highlight cpp %}\n'
    res += node.find('definition').text + node.find('argsstring').text + ';'
    res += '\n{% endhighlight %}\n\n'

    if node.find('briefdescription/para') is not None:
        res += node.find('briefdescription/para').text + '\n\n'

    description_node = node.find('detaileddescription/para')

    if description_node is None:
        return res.strip()

    params_list = description_node.findall('parameterlist/parameteritem')
    if len(params_list) > 0:
        res += '### Parameters\n\n'
        res += '|:--:|:--|\n'
        for elem in params_list:
            params = ', '.join('`' + _.find('parametername').text + '`'
                               for _ in elem.findall('parameternamelist'))
            description = elem.find('parameterdescription/para').text.strip()
            res += '|{}|{}|\n'.format(params, description)
        res += '\n'

    ## Type requirements (TODO)
    
    simplesect = description_node.findall('simplesect')

    res += '### Return value\n\n'
    res += filter_kind(simplesect, 'return').find('para').text + '\n\n'

    res += '### Precondition\n\n'
    res += filter_kind(simplesect, 'pre').find('para').text + '\n\n'

    res += '### Time Complexity\n\n'
    res += filter_kind(simplesect, 'post').find('para').text + '\n\n'

    return res.strip()


def main(filepath):
    dirname = os.path.dirname(__file__)
    try:
        root = ET.fromstring(''.join(_ for _ in open(filepath)))
        functions = [node for node in root.findall('./*/*/memberdef')
                     if node.attrib['kind'] == 'function']
        classes = [node for node in root.findall('./*/innerclass')]

        res = ''
        for node in functions:
            res += function_doc(node) + '\n\n'
        for node in classes:
            path = dirname + '/xml/' + node.attrib['refid'] + '.xml'
            root = ET.fromstring(''.join(_ for _ in open(path)))
            res += class_doc(root.find('compounddef'))

        return res.strip()

    except FileNotFoundError:
        return ''


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('filepath', nargs=1, help='cpp file')
    args = parser.parse_args()
    filepath = args.filepath[0]
    print(main(filepath))
