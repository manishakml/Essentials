/* LC 215
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k > n || k <= 0) {
            return -1;
        }
        sort(nums.begin(),nums.end());
        return nums[n-k];
    }
};

//approach 2
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k > n || k <= 0) {
            return -1;
        }
        priority_queue<int, vector<int>> max_heap(nums.begin(),nums.end());
        for(int i = 0; i < k-1; i++){
            max_heap.pop();
        }
        return max_heap.top();
    }
};

/* Tested
 * Time: O(nlogn) in (1) and O(n) in (2)
 * Space: O(1) in (1) and O(n) in (2)
 */
