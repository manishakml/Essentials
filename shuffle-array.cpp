/* LC 384
 * Shuffle a set of numbers without duplicates.
 * Example:
// Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
 * solution.shuffle();
// Resets the array back to its original configuration [1,2,3].
 * solution.reset();
// Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 */
 
 class Solution {
public:
    vector<int> A;
    Solution(vector<int> nums) {
        A = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return A;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result = A;
        int n = result.size();
        for(int i = 0; i < n; i++) {
            swap(result[i],result[(rand()%(n-i))+i]);
        }
        return result;
    }
};

/* Tested.
 * Note: Initially there is 1/n chance of getting picked for each element. After 1st is filled, there is 1/n-1 chance of getting picked and 1-(1/n) chance of not havong been picked in the 1st round. Therefore, 1/n-1 * (n-1)/n = 1/n. The probability still continues to be 1/n. Similarly, for all elements.
 * Time complexity: O(n)
 * Space complexity: O(1) only for the shuffle.
 */
