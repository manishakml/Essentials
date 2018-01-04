/* LC 198
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& A) {
  int i = 0, e = 0, n = A.size();
  for(int j = 0; j < n; j++) {
    int t = i;
    i = A[j] + e;
    e = max(e, t);
  }
  return max(i,e);
}

/* Tested.
 * Note: This will work for negative numbers as well. Since we take max of inc and exc, negative will get excluded.
 * Time complexity: O(n) where n is the number of houses.
 * Space complexity: O(1)
 */
