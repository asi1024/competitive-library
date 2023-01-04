#pragma once

#include "../template/bit_operation.cpp"
#include "../types/mod.cpp"

// https://github.com/atcoder/ac-library/blob/f669803f78c3acc72671ca6e41b4eeb0469364a8/atcoder/convolution.hpp

constexpr int bsf_constexpr(unsigned int n) {
  int x = 0;
  while (!(n & (1 << x))) x++;
  return x;
}

template <int prim_root, int mod> struct fft_info {
  static constexpr int rank2 = bsf_constexpr(mod - 1);
  using Mod = Modulo<mod, true>;
  std::array<Mod, rank2 + 1> root;   // root[i]^(2^i) == 1
  std::array<Mod, rank2 + 1> iroot;  // root[i] * iroot[i] == 1

  std::array<Mod, std::max(0, rank2 - 2 + 1)> rate2;
  std::array<Mod, std::max(0, rank2 - 2 + 1)> irate2;

  std::array<Mod, std::max(0, rank2 - 3 + 1)> rate3;
  std::array<Mod, std::max(0, rank2 - 3 + 1)> irate3;

  fft_info() {
    root[rank2] = Mod(prim_root) ^ ((mod - 1) >> rank2);
    iroot[rank2] = Mod(1) / root[rank2];
    for (int i = rank2 - 1; i >= 0; i--) {
      root[i] = root[i + 1] * root[i + 1];
      iroot[i] = iroot[i + 1] * iroot[i + 1];
    }

    {
      Mod prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 2; i++) {
        rate2[i] = root[i + 2] * prod;
        irate2[i] = iroot[i + 2] * iprod;
        prod *= iroot[i + 2];
        iprod *= root[i + 2];
      }
    }
    {
      Mod prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 3; i++) {
        rate3[i] = root[i + 3] * prod;
        irate3[i] = iroot[i + 3] * iprod;
        prod *= iroot[i + 3];
        iprod *= root[i + 3];
      }
    }
  }
};

template <int prim_root, int mod>
void butterfly(std::vector<Modulo<mod, true>> &a) {
  using Mod = Modulo<mod, true>;
  int n = int(a.size());
  int h = lg(n);

  static const fft_info<prim_root, mod> info;

  int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
  while (len < h) {
    if (h - len == 1) {
      int p = 1 << (h - len - 1);
      Mod rot = 1;
      for (int s = 0; s < (1 << len); s++) {
        int offset = s << (h - len);
        for (int i = 0; i < p; i++) {
          auto l = a[i + offset];
          auto r = a[i + offset + p] * rot;
          a[i + offset] = l + r;
          a[i + offset + p] = l - r;
        }
        if (s + 1 != (1 << len)) rot *= info.rate2[ctz(~(unsigned int)(s))];
      }
      len++;
    }
    else {
      // 4-base
      int p = 1 << (h - len - 2);
      Mod rot = 1, imag = info.root[2];
      for (int s = 0; s < (1 << len); s++) {
        Mod rot2 = rot * rot;
        Mod rot3 = rot2 * rot;
        int offset = s << (h - len);
        for (int i = 0; i < p; i++) {
          ull mod2 = ll(mod) * mod;
          ull a0 = ull(a[i + offset]);
          ull a1 = ull(a[i + offset + p]) * int(rot);
          ull a2 = ull(a[i + offset + 2 * p]) * int(rot2);
          ull a3 = ull(a[i + offset + 3 * p]) * int(rot3);
          ull a1na3imag = ull(Mod(a1 + mod2 - a3)) * int(imag);
          ull na2 = mod2 - a2;
          a[i + offset] = a0 + a2 + a1 + a3;
          a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
          a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
          a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
        }
        if (s + 1 != (1 << len)) rot *= info.rate3[ctz(~(unsigned int)(s))];
      }
      len += 2;
    }
  }
}

template <int prim_root, int mod>
void butterfly_inv(std::vector<Modulo<mod, true>> &a) {
  using Mod = Modulo<mod, true>;
  int n = int(a.size());
  int h = lg(n);

  static const fft_info<prim_root, mod> info;

  int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
  while (len) {
    if (len == 1) {
      int p = 1 << (h - len);
      Mod irot = 1;
      for (int s = 0; s < (1 << (len - 1)); s++) {
        int offset = s << (h - len + 1);
        for (int i = 0; i < p; i++) {
          auto l = a[i + offset];
          auto r = a[i + offset + p];
          a[i + offset] = l + r;
          a[i + offset + p] =
            (unsigned long long)(mod + ll(l) - ll(r) * ll(irot));
        }
        if (s + 1 != (1 << (len - 1)))
          irot *= info.irate2[ctz(~(unsigned int)(s))];
      }
      len--;
    }
    else {
      // 4-base
      int p = 1 << (h - len);
      Mod irot = 1, iimag = info.iroot[2];
      for (int s = 0; s < (1 << (len - 2)); s++) {
        Mod irot2 = irot * irot;
        Mod irot3 = irot2 * irot;
        int offset = s << (h - len + 2);
        for (int i = 0; i < p; i++) {
          ull a0 = ull(a[i + offset + 0 * p]);
          ull a1 = ull(a[i + offset + 1 * p]);
          ull a2 = ull(a[i + offset + 2 * p]);
          ull a3 = ull(a[i + offset + 3 * p]);
          ull a2na3iimag = ull(Mod((mod + a2 - a3) * ull(iimag)));

          a[i + offset] = a0 + a1 + a2 + a3;
          a[i + offset + 1 * p] = (a0 + (mod - a1) + a2na3iimag) * ll(irot);
          a[i + offset + 2 * p] =
            (a0 + a1 + (mod - a2) + (mod - a3)) * ll(irot2);
          a[i + offset + 3 * p] =
            (a0 + (mod - a1) + (mod - a2na3iimag)) * ll(irot3);
        }
        if (s + 1 != (1 << (len - 2)))
          irot *= info.irate3[ctz(~(unsigned int)(s))];
      }
      len -= 2;
    }
  }
}

template <int prim_root, int mod>
std::vector<Modulo<mod, true>> convolution(std::vector<Modulo<mod, true>> a,
                                           std::vector<Modulo<mod, true>> b) {
  using mod_t = Modulo<mod, true>;
  int size = 1 << lg(int(a.size() + b.size()));
  a.resize(size);
  b.resize(size);
  butterfly<prim_root, mod>(a);
  butterfly<prim_root, mod>(b);
  for (int i = 0; i < size; ++i) a[i] *= b[i];
  butterfly_inv<prim_root, mod>(a);
  const mod_t inv = mod_t(1) / mod_t(size);
  for (auto &x : a) x *= inv;
  return a;
}
