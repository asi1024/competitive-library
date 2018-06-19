int log2ceil(int n) {
  --n;
  n |= n >> 16;
  n |= n >> 8;
  n |= n >> 4;
  n |= n >> 2;
  n |= n >> 1;
  return n + 1;
}

int log2ceil(long long n) {
  --n;
  n |= n >> 32;
  n |= n >> 16;
  n |= n >> 8;
  n |= n >> 4;
  n |= n >> 2;
  n |= n >> 1;
  return n + 1;
}
