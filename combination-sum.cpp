/* LC 39
 * Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [2, 3, 6, 7] and target 7, 
 * A solution set is: 
 * [
 * [7],
 * [2, 2, 3]
 * ]
 */

void helper(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &ans, int pos) {
        if(target < 0) {
            return;
        } else if(target == 0) {
            res.push_back(ans);
            return;
        }
        for(int i = pos; i < candidates.size(); i++){
            ans.push_back(candidates[i]);
            helper(candidates, target-candidates[i], res, ans, i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,res,ans,0);
        return res;
    }
    
    /* Tested.
     * Time complexity: Exponential
     * Space complexity: O(number of operands)
     */
