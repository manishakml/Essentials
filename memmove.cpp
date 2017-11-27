/* Implement memmove */

void *memmove(void *dst, void *src, size_t n) {
  char *p = dst;
  const char *q = src;
  if(p > q){
    p = p+n-1; q=q+n-1;
    // copy backwards
    while(n--) {
      *p-- = *q--;
    }
  } else {
    while(n--){
      *p++ = *q++;
    }
  }
  return dst;
}

/* Not tested.
 * Note: memmove can have overlapping src.dst - hence the different code paths.
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
