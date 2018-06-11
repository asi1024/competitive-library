#pragma once

#include "includes.hpp"

/// @note 型 T の比較が定義されている必要がある
template <typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }

/// @note 型 T の比較が定義されている必要がある
template <typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }
