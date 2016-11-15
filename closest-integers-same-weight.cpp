//EPI 5.4

unsigned long closest_integer_same_weight(unsigned long &n) {
  for(int i = 0; i < 63; i++) {
    if( ((n>>i) & 1) ^ ((n >> (i+1)) & 1) ) {
      n ^= (1UL << i) | (1UL << (i+1));
      return n;
    }
  }
  throw invalid_argument("all bits are 0 or 1");
}
