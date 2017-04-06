#!/bin/bash

set -eu

cd `dirname $0`

INDEX="docs/index.md"

cat docs/header.md >  $INDEX
./cpp/gendoc.sh    >> $INDEX
cat docs/footer.md >> $INDEX
