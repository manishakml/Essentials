/* LC 15
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note: The solution set must not contain duplicate triplets.
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 * [-1, 0, 1],
 * [-1, -1, 2]
 * ]
 */

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size() < 3) return res;
        
        for(int i = 0 ; i < nums.size()-2; i++) {
            if(i==0 || nums[i] != nums[i-1]) {      // To avoid result having duplicate sets
            int j = i+1, k = nums.size()-1;
            while(j < k) {
                if(nums[i]+nums[j]+nums[k] == 0) {
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    j++; k--;
                } else if (nums[i]+nums[j]+nums[k] < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        }
        
        return res;
    }

/* Tested.
 * Note: Eliminate duplicate results, not duplicate input elements.
 * Time complexity: O(n^2) where n is the number of elements.
 * Space complexity: O(1)
 */
