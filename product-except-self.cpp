/* LC 238
 *  Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Solve it without division and in O(n).
 * For example, given [1,2,3,4], return [24,12,8,6].
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include<iostream>
#include<vector>
using namespace std;

int product_array(vector<int>& A) {
  int n = A.size();
  vector<int> o(n);
  int t = 1;
  
  for(int i = 0; i < n; i++) {
    o[i] = t;
    t *= A[i];
  }
  
  int t = 1;
  for(int i = n-1; i >=0 ; i--) {
    o[i] *= t;
    t *= A[i];
  }
  return o;
}

/* Tested.
 * Time complexity: O(n) where n is the number of elements.
 * Space complexity: O(1).
 */
