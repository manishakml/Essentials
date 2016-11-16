//EPI 5.13
unsigned add(const unsigned &a, const unsigned &b) {
  unsigned carryin = 0, carryout = 0, sum = 0, k =1;
  while(k) {
    sum |= (a&k) ^ (b&k) ^ carryin;
    carryout = (carryin&a) | (carryin&b) | (a&b);
    carryin = carryout << 1;
    k <<= 1;
  }
  return sum;
}

unsigned multiply(const unsigned &x, const unsigned &y) {
  unsigned res=0,k=1, tmpy = y;
  while(k) {
    if(x & k) {
      res = add(res,tmpy);
    }
     k <<= 1;
     tmpy <<= 1;
  }
  return res;
}
