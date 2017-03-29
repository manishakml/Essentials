/* LC 278
 *  You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 * You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API. 
 */
#include<iostream>
using namespace std;

int findBad(int n) {
  int l = 1, r = n, m;
  if (n == 0) return 0;
  while ( l < r ) {
    m = l + ((r-l)>>1);
    if (isBadVersion(m)) {
      r = m;
    } else {
      l = m+1;
    }
  }
  return r;
}

/* Tested.
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */
