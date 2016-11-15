// EPI 5.1
short parity_compute (unsigned long n) {
  short res = 0;
  while (n) {
    n = (n & (n-1));
    res ^= 1;
  }
  return res;
}

unsigned long 16-BIT  = pow(2,16)
short pc[16-BIT];
for(unsigned long i = 0; i < 16-BIT; i++) {
  pc[i] = parity_compute(i);
}

short parity_compute2 (unsigned long n) {
  return pc[n >> 48] ^ pc[(n >> 32) & 0xffff] ^ pc[(n >> 16) & 0xffff] ^ pc[n & 0xffff];
}
