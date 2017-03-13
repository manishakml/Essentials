/* LC 254
 * Numbers can be regarded as product of its factors. For example,
 * 8 = 2 x 2 x 2;
 * = 2 x 4.
 * Write a function that takes an integer n and return all possible combinations of its factors.
 * Note: 
 * You may assume that n is always positive.
 * Factors should be greater than 1 and less than n.
 * Examples: 
 * input: 1
 * output: 
 * []
 * input: 37
 * output: 
 * []
 * input: 12
 * output:
 * [
 * [2, 6],
 * [2, 2, 3],
 * [3, 4]
 * ]
 * input: 32
 * output:
 * [
 * [2, 16],
 * [2, 2, 8],
 * [2, 2, 2, 4],
 * [2, 2, 2, 2, 2],
 * [2, 4, 4],
 * [4, 8]
 * ]
 */
 #include <iostream>
 #include <cmath>
 #include <vector>
 using namespace std;
 
 void dfs(int n, vector<vector<int>>& res, vector<int>& ans, int pos) {
  int limit = sqrt(n);
  for(int i = pos; i <= limit; i++) {
    if(n%i == 0) {
      ans.push_back(i);
      dfs(n/i,res,ans,i);
      ans.push_back(n/i);
      res.push_back(ans);
      ans.pop_back();
      ans.pop_back();
    }
  }
 }
 vector<vector<int>> getFactors(int n) {
  vector<vector<int>> res;
  if (n < 4) {
    return res;
  }
  vector<int> ans;
  dfs(n,res,ans,2);
  return res;
 }
 }
 
 /* Tested.
  * Time complexity : 2^n (exponential)
  * Space complexity: 
  */
