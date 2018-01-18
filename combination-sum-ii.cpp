/* LC 40
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

class Solution {
public:
    void helper(vector<int> &A, vector<bool> &used, vector<vector<int>> &res, vector<int> &ans, int sum, int remain,int start){
        if(remain < 0) {
            return;
        } else if(remain == 0){
            res.push_back(ans);
        } else {
            for(int i = start; i < A.size(); i++){
                if(used[i] || A[i] == A[i-1] && !used[i-1]) continue;
                if(A[i] > sum) {
                    break;
                }
                used[i] = true;
                ans.push_back(A[i]);
                helper(A,used,res,ans,sum,remain-A[i],i+1);
                used[i] = false;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        vector<bool> used(candidates.size());
        helper(candidates,used,res,ans,target,target,0);
        return res;
    }
};

/* Tested.
 * Time: Exponential
 * Space: O(n)
 */
