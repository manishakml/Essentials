/* LC 26
 * 
 */
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int w = 0, r = 1, n = nums.size();
        if(n < 2) {
            return n;
        }
        while(r < n) {
            if (r < n && nums[r] == nums[w]) {
                r++;
                continue;
            } else {
                nums[++w] = nums[r++];
            }
        }
        return w+1;
}

/* Tested
 * Note: Work out all corner cases. Good egs: [1,1,2], [1,1] etc.
 * Time complexity: O(n) where n is the number of elements.
 * Space complexity: O(1)
 */
