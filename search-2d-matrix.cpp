/* LC 74
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 * Consider the following matrix:
 * [
 * [1,   3,  5,  7],
 * [10, 11, 16, 20],
 * [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */
 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) {
            return false;
        }
        int m = matrix[0].size();
        
        int l = 0, r = m*n -1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(matrix[mid/m][mid%m] == target) {
                return true;
            } else if (matrix[mid/m][mid%m] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};

/* Tested.
 * Note: Use (l+r)/2 and not >> 1. Gives TLE on leetcode.
 * Note2: Treat it as a regular sorted list.
 * Time complexity: O(log mn)
 * Space complexity: O(1)
 */
