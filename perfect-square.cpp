/* LC 367
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 * Note: Do not use any built-in library function such as sqrt.
 * Example 1:
 * Input: 16
 * Returns: True
 * Example 2:
 * Input: 14
 * Returns: False
 */

#include<iostream>
using namespace std;

bool perfect_sqr(int n) {
  int l = 1, r = n;
  if(n <= 0) return false;
  
  while(l <= r) {
    long m = l + ((r-l)>>1);
    if(m*m == n) {
      return true;
    } else if(m*m < n) {
      l = (int)m + 1;
    } else {
      r = (int)m - 1;
    }
  }
  return false;
}

/* Tested.
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */
