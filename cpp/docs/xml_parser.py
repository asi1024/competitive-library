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
    name = node.find('compoundname').text.strip()

    res = ''

    sections = node.findall('sectiondef')
    public_funcs = filter_kind(sections, 'public-func')

    if public_funcs:
        public_funcs = public_funcs.findall('memberdef')
        fnames = set()

        for elem in public_funcs:
            fname = elem.find('name').text.strip()
            if fname == name:
                fname = '(constructor)'
            elif fname == '~' + name:
                fname = '(destructor)'
            fnames.add(fname)

        fnames = sorted(list(fnames))
        res += '## Member functions\n\n'

        for num, fname in enumerate(fnames):
            res += '### [{}] {}\n'.format(num + 1, fname)
            if fname == '(constructor)':
                fname = name
            elif fname == '(destructor)':
                fname = '~' + name
            nodes = [_ for _ in public_funcs if _.find('name').text.strip() == fname]

            res += '{% highlight cpp %}\n'
            for elem in nodes:
                typestr = elem.find('type').text
                res += typestr.strip() + ' ' if typestr else ''
                res += elem.find('name').text.strip()
                res += elem.find('argsstring').text.strip() + ';\n'
            res += '{% endhighlight %}\n\n'

            for elem in nodes:
                brief = elem.find('briefdescription/para')
                if brief is not None:
                    res += '- {}\n'.format(brief.text.strip())
            res += '\n'

            # Parameters
            paramstr = ''
            for elem in nodes:
                params = elem.findall(
                    'detaileddescription/para/parameterlist/parameteritem')
                if params:
                    for param in params:
                        pl = param.findall('parameternamelist/parametername')
                        pnames = ', '.join(_.text.strip() for _ in pl)
                        descrip = param.find('parameterdescription/para').text.strip()
                        paramstr += '|{}|{}|\n'.format(pnames, descrip)

            if paramstr:
                res += '#### Parameters\n\n'
                res += '|:--:|:--|\n'
                res += paramstr + '\n'

            sects = elem.findall('detaileddescription/para/simplesect')

            # Return value
            for elem in nodes:
                ret = filter_kind(sects, 'return')
                if ret is not None:
                    ret_text = ret.find('para').text.strip()
                    res += '#### Return value\n\n'
                    res += '- {}\n\n'.format(ret_text)
                    break

            # Return value
            for elem in nodes:
                pre = filter_kind(sects, 'pre')
                if pre is not None:
                    pre_text = pre.find('para').text.strip()
                    res += '#### Precondition\n\n'
                    res += '- {}\n\n'.format(pre_text)
                    break

            # Time complexity
            for elem in nodes:
                complexity = filter_kind(sects, 'post')
                if complexity is not None:
                    complexity_text = complexity.find('para').text.strip()
                    res += '#### Time complexity\n\n'
                    res += '- {}\n\n'.format(complexity_text)
                    break

            res += '---------------------------------------\n\n'

    return res


def function_doc(node):
    res = ''
    res += '## {}\n\n'.format(node.find('name').text.strip())

    res += '{% highlight cpp %}\n'
    res += node.find('definition').text.strip() + node.find('argsstring').text.strip() + ';'
    res += '\n{% endhighlight %}\n\n'

    if node.find('briefdescription/para') is not None:
        res += '- {}\n\n'.format(node.find('briefdescription/para').text.strip())

    description_node = node.find('detaileddescription/para')

    if description_node is None:
        return res.strip()

    params_list = description_node.findall('parameterlist/parameteritem')
    if len(params_list) > 0:
        res += '### Parameters\n\n'
        res += '|:--:|:--|\n'
        for elem in params_list:
            params = ', '.join('`' + _.find('parametername').text.strip() + '`'
                               for _ in elem.findall('parameternamelist'))
            description = elem.find('parameterdescription/para').text.strip()
            res += '|{}|{}|\n'.format(params, description)
        res += '\n'

    ## Type requirements (TODO)
    
    simplesect = description_node.findall('simplesect')

    res += '### Return value\n\n'
    res += '- {}\n\n'.format(filter_kind(simplesect, 'return').find('para').text.strip())

    res += '### Precondition\n\n'
    res += '- {}\n\n'.format(filter_kind(simplesect, 'pre').find('para').text.strip())

    res += '### Time Complexity\n\n'
    res += '- {}\n\n'.format(filter_kind(simplesect, 'post').find('para').text.strip())

    res += '---------------------------------------\n\n'

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
