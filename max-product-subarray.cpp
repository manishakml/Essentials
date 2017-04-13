/* LC 152
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */
 #include<iostream>
 #include<vector>
 #include<cmath>
 using namespace std;
 
 int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int cur_min = nums[0];
        int cur_max = nums[0];
        int res = nums[0];
        for(int i = 1; i < n; i++) {
            int t = cur_max;
            cur_max = max(cur_max*nums[i],max(cur_min*nums[i],nums[i]));
            cur_min = min(cur_min*nums[i],min(t*nums[i],nums[i]));
            res = max(res,cur_max);
        }
        return res;        
    }
    
/* Tested.
 * Note: Comparison of element vs cur_max/min element is the same as max subarray qn. Comparison with the opposite kind is necessary if the element is negative since negation might change signs and also multiplying -ve number by a big number yields a smaller number.
 * Time complexity: O(n) where n is the number of elements.
 * Space complexity: O(1)
 */
