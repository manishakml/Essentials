//EPI 5.3
long bit_reversal(const long n) {
  for(int i = 0; i < 32; i++) {
    if (((n >> i) & 1) ^ ((n >> (63-i)) & 1) ) {
      n ^= (1L << i) | (1L << (63-i));
    }
  }
  return n;
}

int 16-BIT = pow(2,16);
int pc_rev[16-BIT];
for(int i = 0; i < 16-BIT; i++) {
  pc_rev[i] = bit_reversal(i);
}

long bit_reversal1(const long n) {
  return pc_rev[(n >> 48) & 0xffff] | (pc_rev[(n >> 32) & 0xffff] << 16) | (pc_rev[(n >> 16) & 0xffff] << 32) | (pc_rev[n & 0xffff] << 48);
}
