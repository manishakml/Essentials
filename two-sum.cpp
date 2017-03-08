/* LC 1
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */
 
 #include <iostream>
 #include <map>
 #include <vector>
 using namespace std;
 
 vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> m;
        
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(target-nums[i]) != m.end()) {
                res.push_back(m[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
 }
 
 /* Tested.
  * Time complexity: O(n) where n is the number of elements in the list.
  * Space complexity: O(n).
  */
