/* LC 31
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */
#include<iostream>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return;
        int k = -1;
        for(int i = n-2; i >=0; i--) {
            if(nums[i] < nums[i+1]) {
                k = i;
                break;
            }
        }
        if(k == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int l = -1;
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        swap(nums[k],nums[l]);
        reverse(nums.begin()+k+1,nums.end());
    }
    
    /* Tested.
     * Time complexity: O(n) where n is the number of elements.
     * Space complexity: O(1).
     */
