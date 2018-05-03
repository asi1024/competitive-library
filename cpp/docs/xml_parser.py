#!/usr/bin/env python

import argparse
import re
import xml.etree.ElementTree as ET


def get_class(node):
    return [elem for elem in node.findall('./*/*/innerclass')]

def get_typedef(node):
    return [elem for elem in node.findall('./*/*/memberdef')
            if elem.attrib['kind'] == 'typedef']

def get_function(node):
    return [elem for elem in node.findall('./*/*/memberdef')
            if elem.attrib['kind'] == 'function']

def tostring(node):
    return re.sub('<.*?>', '', ET.tostring(node).decode('utf-8').strip())

def filter_kind(nodes, tag):
    return [node for node in nodes if node.attrib['kind'] == tag][0]

def function(node):
    res = ''
    res += '## {}\n\n'.format(node.find('name').text)

    res += '{% highlight cpp %}\n'
    res += node.find('definition').text + node.find('argsstring').text + ';'
    res += '{% endhighlight %}\n\n'

    if node.find('briefdescription/para') is not None:
        res += node.find('briefdescription/para').text + '\n\n'

    description_node = node.find('inbodydescription/para')

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
    try:
        res = ''
        root = ET.fromstring(''.join(_ for _ in open(filepath)))
        for elem in get_function(root):
            res += function(elem) + '\n\n'
        return res.strip()
    except FileNotFoundError:
        return ''


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('filepath', nargs=1, help='cpp file')
    args = parser.parse_args()
    filepath = args.filepath[0]
    main(filepath)
