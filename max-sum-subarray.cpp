/* LC 53
 *  Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6. 
 */

#include<iostream>
using namespace std;

int max_sum_subarray(vector<int>& A) {
  int cur_max = A[0], maxSum = A[0];
  int n = A.size(); 
  for(int i = 0; i < n; i++) {
    cur_max = max(A[0], A[0]+cur_max);
    maxSum = max(maxSum, cur_max);
  }
  return maxSum;
}

/* Tested.
 * Time complexity: O(n) where n is the number of elements.
 * Space complexity: O(1).
 */
