//EPI 5.14
unsigned divide(const unsigned &dividend, const unsigned &divisor) {
  if(dividend < divisor) return 0;
  unsigned quotient;
  unsigned curDivisor = divisor;
  unsigned quotientBase = 1;
  
  while(dividend >= divisor) {
    if(dividend >= curDivisor) {
      dividend -= curDivisor;
      quotient += quotientBase;
      qutientBase *= 2;
      curDivisor *= 2;
    } else {
      quotientBase  >> 1 ;
      curDivisor >> 1;
    }
  }
  return quotient;
}
