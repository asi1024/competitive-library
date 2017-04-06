[![GitHub license](https://img.shields.io/github/license/asi1024/competitive-library.svg)](https://github.com/asi1024/competitive-library/blob/master/LICENSE)
[![Build Status](https://travis-ci.org/asi1024/competitive-library.svg?branch=master)](https://travis-ci.org/asi1024/competitive-library)

# competitive-library

競技プログラミング用ライブラリ管理ツール

## Usage

1. Fork it.
2. `cpp/[category]/[filename.cpp]` を好みに追加したり書き換えたりする
3. `cpp/[AOJ-Problem-ID.cpp]` に書いたライブラリを include して問題を解く (optional)

### Automated Testing
4. `CXX` と `CXXFLAGS` を指定して `cpp/spec.sh` を走らせる (例: `CXX=g++ CXXFLAG="--std=c++14 -O2 -Wall" ./cpp/spec.sh`)
5. (optional) Travis CI の方の設定をいい感じにする ([こんな感じ](https://travis-ci.org/asi1024/competitive-library/jobs/219386700#L307) になる)

### Generates Documentation
4. `./gendoc.sh` を走らせると， `docs/index.md` が生成される ([こんな感じ](https://github.com/asi1024/competitive-library/blob/master/docs/index.md) になる)
5. GitHub Pages の設定をする ([こんな感じ](https://asi1024.github.io/competitive-library/) になる)

## How to Contribute
- [Pull Request](https://github.com/asi1024/competitive-library/pull/new/master)
- [Issue](https://github.com/asi1024/competitive-library/issues/new)

## Contributors
- [Contributors](https://github.com/asi1024/competitive-library/graphs/contributors)
