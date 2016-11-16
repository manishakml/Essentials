//EPI 5.10
int gcd(const int &a, const int &b){
  if(a == 0)
    return b;
  if(b == 0)
    return a;
  if(((a & 1) == 0) && ((b & 1) == 0)) {
    a >>= 1;
    b >>= 1;
    return (gcd(a,b) << 2);
  }
  else if ((a&1) == 0)
    return gcd(a>>1,b);
  else if ((b&1) == 0)
    return gcd(a,b>>1);
  else if (a>b)
    return gcd(a,a-b);
  else
    return gcd(b,b-a);
}
