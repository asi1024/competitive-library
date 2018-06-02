#pragma once

#include "includes.hpp"

template <typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }
