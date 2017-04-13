/* LC 46
 * Given a collection of distinct numbers, return all possible permutations.
 * For example,
 * [1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include<iostream>
#include<vector>
using namespace std;

void helper(vector<int> &nums, vector<vector<int>> &res, int s, int e) {
        if(s == e) {
            res.push_back(nums);
            return;
        }
        for(int i = s; i <= e; i++) {
            swap(nums[i],nums[s]);
            helper(nums,res,s+1,e);
            swap(nums[i],nums[s]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n==0) return res;
        if(n==1) {res.push_back(nums); return res;};
        helper(nums,res,0,n-1);
        return res;
    }

/* Tested.
 * Note1: Refer http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/ for explanation.
 * Note2: If you do not use &nums in helper args, you do not need the second swap since new nums copy is created for every iteration. However, this is not space-efficient.
 * Note3: Comparing s with e=n-1 and not with n makes it efficient for not having to process swaps on the last element iteration. Refer to the tree in the link above and see why processing can stop at 3rd layer as opposed to adding a 4th layer to swap with itself.
 * Time complexity: O(n*n!) where n is the number of elements. n! because there are n! number of results. n*n! because we are outputting n items n! times. http://stackoverflow.com/questions/5363619/complexity-of-recursive-string-permutation-function
 * Space complexity: O(n) since only n stack frames needed at any point (equal to the height of the recursion tree)
 */
