#!/bin/bash

set -eu

cd `dirname $0`

INDEX="docs/index.md"

cat docs/header.md  >  $INDEX
./cpp/gendoc.sh C++ >> $INDEX
cat docs/footer.md  >> $INDEX
