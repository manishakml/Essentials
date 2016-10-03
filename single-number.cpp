/**
 * Leetcode 136
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for(int i = 0; i < nums.size(); i++){
            xor1 = xor1 ^ nums[i];
        }
        return xor1;
 }
 
 /**
  * Time complexity: O(n) where n is the number of elements in the array.
  * Space complexity: O(1).
  * Tested.
  */
