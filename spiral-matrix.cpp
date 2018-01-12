/* LC 54
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * For example,
 * Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
 * You should return [1,2,3,6,9,8,7,4,5].
 */
 
 class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if ( n == 0 ) return res;
        int m = matrix[0].size();
        if(m == 0) return res;
        
        int u = 0, d = n-1, l = 0, r = m-1;
        while(true) {
            for(int C = l; C <= r; C++) {
                res.push_back(matrix[u][C]);
            }
            u++;
            if(u > d) {
                break;
            }
            
            for(int R = u; R <= d; R++) {
                res.push_back(matrix[R][r]);
            }
            r--;
            if(r < l) {
                break;
            }
            
            for(int C = r; C >= l; C--) {
                res.push_back(matrix[d][C]);
            }
            d--;
            if(d < u) {
                break;
            }
            
            for(int R = d; R >= u; R--) {
                res.push_back(matrix[R][l]);
            }
            l++;
            if(l > r) {
                break;
            }
        }
        return res;
    }
};

/* Tested.
 * Time complexity: O(n*m) since it has to traverse all elements.
 * Space complexity: O(1)
 */
