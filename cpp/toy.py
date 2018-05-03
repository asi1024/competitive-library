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

def print_function(node):
    print('## {}\n'.format(node.find('name').text))

    print('```')
    print(node.find('definition').text + node.find('argsstring').text)
    print('```\n')

    if node.find('briefdescription/para') is not None:
        print(node.find('briefdescription/para').text + '\n')

    description_node = node.find('inbodydescription/para')

    if description_node is None:
        return

    params_list = description_node.findall('parameterlist/parameteritem')
    if len(params_list) > 0:
        print('|:--:|:--|')
        for elem in params_list:
            params = ', '.join(_.find('parametername').text
                               for _ in elem.findall('parameternamelist'))
            description = elem.find('parameterdescription/para').text.strip()
            print('|{}|{}|'.format(params, description))
        print()

    ## Type requirements (TODO)
    
    simplesect = description_node.findall('simplesect')

    print('### Return value\n')
    print(filter_kind(simplesect, 'return').find('para').text + '\n')

    print('### Precondition')
    print(filter_kind(simplesect, 'pre').find('para').text + '\n')

    print('### Time Complexity')
    print(filter_kind(simplesect, 'post').find('para').text + '\n')


def main(filepath):
    root = ET.fromstring(''.join(_ for _ in open(filepath)))

    for elem in get_function(root):
        print_function(elem)
    

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('filepath', nargs=1, help='cpp file')
    args = parser.parse_args()
    filepath = args.filepath[0]
    main(filepath)
