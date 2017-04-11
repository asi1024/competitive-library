#!/bin/bash

set -eu

cd `dirname $0`

INDEX="docs/index.md"

cat docs/header.md          >  $INDEX
./scripts/gendoc.sh C++ cpp >> $INDEX
cat docs/footer.md          >> $INDEX
