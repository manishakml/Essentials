/* LC 167
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */
 #include <iostream>
 #include <vector>
 using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int l = 0, r = numbers.size()-1;
        
        while(l < r) {
            if(numbers[l] + numbers[r] == target) {
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            } else if(numbers[l] + numbers[r] < target) {
                l++;
            } else {
                r--;
            }
        }
        return res;
 }
 
 /* Tested.
  * Time complexity: O(n) where n is the number of elements in the list.
  * Space complexity: O(1).
  */ 
