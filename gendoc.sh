#!/bin/bash

set -eu

cd `dirname $0`

INDEX="docs/index.md"

cat docs/Template.md > $INDEX
./cpp/gendoc.sh      > $INDEX
