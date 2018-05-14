#!/bin/bash

set -eu

DIR=`dirname $0`

cd ${DIR}/cpp/docs
doxygen
cd ../..

rm -rf docs/cpp docs/ocaml
python cpp/docs/documents.py
python cpp/docs/title.py        > docs/cpp/index.md
python ocaml/docs/documents.py
python ocaml/docs/title.py      > docs/ocaml/index.md
