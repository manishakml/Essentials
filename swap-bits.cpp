// EPI 5.2 
long swap_bits(long n, const int &i, const int &j) {
  int a = (n >> i) & 1;
  int b = (n >> j) & 1;
  
  if (a ^ b) {
    n ^= (1L << i) | (1L << j);
  }
  return n;
}
