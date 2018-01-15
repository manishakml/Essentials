/* LC 283
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return;
        }
        int w = 0, r = 0;
        
        while(r < n){
            if(nums[r] != 0) {
                nums[w++] = nums[r];
            }
            r++;
        }
        
        while(w < n){
            nums[w] = 0;
            w++;
        }
    }
};

/* Tested.
Time : O(n)
Space: O(1)
*/
