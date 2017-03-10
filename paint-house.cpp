/* LC 256
 * There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
 * The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
 * Note:
 * All costs are positive integers.
 */
 
 #include<iostream>
 #include<algorithm>
 #include<cmath>
 using namespace std;
 
 int min_cost(vector<vector<int>>& A) {
  int n = A.size();
  if (n == 0) {
    return 0;
  }
  
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      A[i][j] += min(A[i-1][(j+1)%3], A[i-1][(j+2)%3]);
    }
  }
  
  return min(A[n-1][0], min(A[n-1][1], A[n-1][2]));
 }
 
 /* Tested.
  * Time complexity: O(n) where n is the number of houses.
  * Space complexity: O(1)
  */
