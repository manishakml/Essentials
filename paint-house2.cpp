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

/* Tested.
 * Note: O(nk^2) approach is direct modification of paint-house1 where extra k loop scans the minimum of prev level.
 * Time complexity: O(nk) where n is the number of houses, k is the number of colors.
 * Space complexity: O(1).
 */
