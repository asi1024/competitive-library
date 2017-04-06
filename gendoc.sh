#!/bin/bash

set -eu

cd `dirname $0`

INDEX="docs/Index.md"

cat docs/Template.md >  $INDEX
echo ""              >> $INDEX
./cpp/gendoc.sh      >> $INDEX
