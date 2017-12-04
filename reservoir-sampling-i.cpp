/* LC 398
 * Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
 * Note:
 * The array size can be very large. Solution that uses too much extra space will not pass the judge.
 * Example:
 * int[] nums = new int[] {1,2,3,3,3};
 * Solution solution = new Solution(nums);
 * // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 * solution.pick(3);
 * // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
 * solution.pick(1);
 */
 
 int pick(vector<int> &nums, int target) {
        int res = -1;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != target) continue;
            //increase count of target seen so far
            count++;
            //there is 1/count probability of choosing any of the indices of target; if the rand() results in 0, we will pick this idx, otherwise it will remain as the prev res (This condition is arbitrary, the condition could be anything.
            if(rand()%count == 0) {
                res = i;
            }
        }
        return res;
 }
 
 /* Tested.
  * Time complexity: O(n)
  * Space complexity: O(1)
  */
