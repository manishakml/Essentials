/* LC 50
 * Implement pow(x, n).
 */

#include<iostream>
using namespace std;

double myPow(double x, int n) {
  if(n == 0) return 1;
  double t = myPow(x,n/2);
  
  return (n%2)? n>0? x*t*t : t*t/x : t*t;
}

//iterative - look for good explanation here : https://discuss.leetcode.com/topic/40546/iterative-log-n-solution-with-clear-explanation/11
double myPow(double x, int n) {
  double ret = 1.0;
  long absN = abs((long)n);   //To handle overflow in case of n=INT_MIN
  
  while(absN > 0) {
    if(absN&1) ret *= x;
    x *= x;
    absN >= 1
  }
  return (n < 0)? 1/ret : ret;
}

/* Tested.
 * Time complexity: O(log(n))
 * Space complexity: O(1) iterative or O(log(n)) for call stack in case of recursive.
 */
