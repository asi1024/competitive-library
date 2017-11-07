#!/bin/bash

set -eu

cd `dirname $0`

INDEX="docs/index.md"

cat docs/header.md   >  $INDEX
./cpp/docs/title.py  >> $INDEX
./cpp/docs/documents.py
cat docs/footer.md   >> $INDEX
