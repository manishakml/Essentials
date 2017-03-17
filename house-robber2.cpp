/* LC 213
 * Note: This is an extension of House Robber.
 * After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

#include<iostream>
#include<vector>
using namespace std;

int helper(int l, int r, vector<int>& A) {
        int i = 0, e = 0, n = A.size();
        
        for(int j = l; j <= r; j++) {
            int t = i;
            i = A[j] + e;
            e = max(e,t);
        }
        return max(i,e);
    }
int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n? nums[0] : 0;  
        return max(helper(0,n-2,nums), helper(1,n-1,nums));
}

/* Tested.
 * Time complexity: O(n) where n is the number of houses.
 * Space complexity: O(1).
 */
