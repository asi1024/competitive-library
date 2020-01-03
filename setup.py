#!/usr/bin/env python

from setuptools import setup, find_packages

setup(
    name='competitive-programming-library',
    version='1.0',
    description='competitive-programming-library',
    author='Akifumi Imanishi',
    author_email='akifumi.imanishi@gmail.com',
    url='https://github.com/asi1024/competitive-library',
    packages=find_packages(include=('script',)),
    scripts=['preprocessor']
)
