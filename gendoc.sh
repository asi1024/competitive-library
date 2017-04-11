#!/bin/bash

set -eu

cd `dirname $0`

INDEX="docs/index.md"

cat docs/header.md          >  $INDEX
./scripts/gendoc.sh C++ cpp >> $INDEX
./scripts/cpp2doc.sh
cat docs/footer.md          >> $INDEX
