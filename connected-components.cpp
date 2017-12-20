/* LC 323
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
 * Example 1:
     0          3
     |          |
     1 --- 2    4
 * Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
 * Example 2:
     0           4
     |           |
     1 --- 2 --- 3
 * Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
 * Note:
 * You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */
 
 #include<iostream>
 #include<vector>
 #include<map>
 using namespace std;
 
 void dfs(int f, vector<int> &s, vector<bool> &vis, unordered_map<int,vector<int>> &m) {
  vis[f] = true;
  
  for(int i = 0; i < s.size(); i++) {
    if(!vis[s[i]]) {
      dfs(s[i],m[s[i]],vis,m);
    }
  }
 }
 
 int count(int n, vector<pair<int, int>> &A) {
  int c = 0;
  unordered_map<int, vector<int>> m;
  vector<bool> vis(n,false);
  
  for(int i = 0; i < n; i++) {
    m[i] = {};
  }
  for(int i = 0; i < A.size(); i++) {
    m[A[i].first].push_back(A[i].second);
    m[A[i].second].push_back(A[i].first);
  }
  
  for(auto it = m.begin(); it != m.end(); it++) {
    if(!vis[it->first]) {
      dfs(it->first,it->second,vis,m);
      c++;
    }
   }
   return c;
 }
 
 /* Tested.
  * Time complexity: O(n) since it visits each node only once.
  * Space complexity: O(max(n,2m))
  */
