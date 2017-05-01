/* LC 265
 * There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
 * The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
 * Note:
 * All costs are positive integers.
 * Follow up:
 * Could you solve it in O(nk) runtime?
 */
 
 #include <iostream>
 #include <vector>
 #include <climits>
 #include <cmath>
 using namespace std;
 
 int paint(vector<vector<int>>& c) {
  if (c.size() == 0 || c[0].size() == 0) return 0;
  int n = c.size(), k = c[0].size();
  if(k == 1 && n > 1) return INT_MAX;
  
  int f=-1, s=-1, ans = INT_MAX;
  
  for(int j = 0; j < k; j++) {
    if(f == -1 || c[0][j] < c[0][f]) {
      s=f;
      f=j;
    } else if(s==-1 || c[0][j] < c[0][s]) {
      s=j;
    }
  }
  
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < k; j++) {
      costs[i][j] += (j == f)? c[i-1][s]:c[i-1][f];
    }
    
    f = -1, s = -1;
    for(int j = 0; j < k; j++) {
      if(f == -1 || c[i][j] < c[i][f]) {
        s=f;
        f=j;
      } else if(s == -1 || c[i][j] < c[i][s]) {
        s=j;
      }
    }
  }
  
  for(int j = 0; j < k; j++) {
    ans = min(ans, c[n-1][j]);
  }
  
  return ans;
}

// Without repeating the logic for f and s. Also, modularizing.
void find_min2(vector<vector<int>> &costs, int& f, int& s, int& k, int& i){
        for(int j = 0; j < k; j++) {
            if(f == -1 || costs[i][j] < costs[i][f]) {
                s=f;
                f=j;
            } else if(s==-1 || costs[i][j] < costs[i][s]) {
                s=j;
            }
        }
    }
    
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
  
        int n = costs.size(), k = costs[0].size();
  
        if(k == 1 && n > 1) return INT_MAX;
  
        int f, s, ans = INT_MAX;
  
        for(int i = 0; i < n; i++) {
            if(i > 0) {
                for(int j = 0; j < k; j++) {
                    costs[i][j] += (j == f)? costs[i-1][s]:costs[i-1][f];
                }
            }
            f = -1, s = -1;
            find_min2(costs,f,s,k,i);
        }
        
        for(int j = 0; j < k; j++) {
            ans = min(ans, costs[n-1][j]);
        }
        return ans;
    }

// If original array cannot be modified, then use explicit O(k) space. We need sval and fval since dp is getting modified. Also, for cases where s remains -1 (n: 1), we need the conditional assignment for fval and sval.
void find_min2(int dp[], int& f, int& s, int& k){
        for(int j = 0; j < k; j++) {
            if(f == -1 || dp[j] < dp[f]) {
                s=f;
                f=j;
            } else if(s==-1 || dp[j] < dp[s]) {
                s=j;
            }
        }
    }
    
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) return 0;
  
        int n = costs.size(), k = costs[0].size();
  
        if(k == 1 && n > 1) return INT_MAX;
  
        int f, s, ans = INT_MAX, fval,sval;
        
        int dp[k];
        for(int j = 0; j < k; j++) {
            dp[j] = costs[0][j];
        }
    
        for(int i = 0; i < n; i++) {
            if(i > 0) {
                for(int j = 0; j < k; j++) {
                    dp[j] = costs[i][j] + ((j == f)? sval:fval);
                }
            }
            f = -1, s = -1;
            find_min2(dp,f,s,k);
            if(f > -1) fval = dp[f];
            if(s > -1) sval = dp[s];
        }
        
        return dp[f];
    }
/* Tested.
 * Note: O(nk^2) approach is direct modification of paint-house1 where extra k loop scans the minimum of prev level.
 * Time complexity: O(nk) where n is the number of houses, k is the number of colors.
 * Space complexity: O(1).
 */
