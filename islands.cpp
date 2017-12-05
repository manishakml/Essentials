/* LC 200
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 * Example 1:
 * 11110
 * 11010
 * 11000
 * 00000
 * Answer: 1
 * Example 2:
 * 11000
 * 11000
 * 00100
 * 00011
 * Answer: 3
 */
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>>& A, int n, int m, int i, int j, vector<vector<bool>>& vis) {
        return (i >= 0 && i < n && j >=0 && j < m && A[i][j] == '1' && !vis[i][j]);
    }
    
    void dfs(vector<vector<char>>& A, int n, int m, int i, int j, vector<vector<bool>>& vis) {
        int R[] = {0,1,0,-1};
        int C[] = {1,0,-1,0};
        vis[i][j] = true;
        
        for(int k = 0; k < 4; k++) {
            if(isSafe(A,n,m,i+R[k],j+C[k],vis)) {
                dfs(A,n,m,i+R[k],j+C[k],vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int c = 0;
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid,n,m,i,j,vis);
                    c++;
                }
            }
        }
        return c;
    }

//Approach 2 withoutvisited matrix
bool isSafe(vector<vector<char>>& A, int n, int m, int i, int j) {
        return (i >= 0 && i < n && j >=0 && j < m && A[i][j] == '1');
    }
    
    void dfs(vector<vector<char>>& A, int n, int m, int i, int j) {
        int R[] = {0,1,0,-1};
        int C[] = {1,0,-1,0};
        A[i][j] = -1;
        
        for(int k = 0; k < 4; k++) {
            if(isSafe(A,n,m,i+R[k],j+C[k])) {
                dfs(A,n,m,i+R[k],j+C[k]);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int c = 0;
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        //vector<vector<bool>> vis(n,vector<bool>(m,0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid,n,m,i,j);
                    c++;
                }
            }
        }
        return c;
    }
    
/* Tested.
 * Time complexity: O(nm).
 * Space complexity: O(nm) for both. (Vis matrix and call stack in (1) and call stack in (2)).
 */
