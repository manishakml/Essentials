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
       // you have to put both directions in. Assume you have (1,2) and (3,1). If you did not put (1,3) in, while processing node 1, we would have only marked 1 and 2 as visited. Then, we would process 3 in its turn since it was unvisited. This would lead to 2 components when in reality there is only one.
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

/* If asked in the form of email id mappings - Given, a mapping of alias and email ids, group the same people together.
{{Ed, {ed@g,e@g}}, {Ed S, ed@g, es@g}, {EdS es@g, eds@g}, {man, man@g}}}*/

void dfs(vector<pair<string,vector<string>>> A, int s, int n, vector<string> &ans, unordered_map<string,vector<int>> &m, vector<bool> &vis){
     vis[s] = true;
     pair<string, vector<string>> p = A[s];
     ans.push_back(p.first);
     
     //for all emails of that object
     for(string e: p.second){
          //for each idx associated with that email
          for(int i = 0; i < m[e].size();  i++){
               if(!vis[i]){
                    dfs(A,i,n,ans,m,vis);
               }
          }
     }
}

vector<vector<string>> group(vector<pair<string,vector<string>>> &A){
     int n = A.size();
     unordered_map<string, vector<int>> m; //map of email id and idxs
     //for each email id, create a list of objects associated with it
     for(int i = 0; i < A.size(); i++){
          for(string e : A[i].second) {
               m[e].push_back(i);
          }
     }
     int c = 0;
     vector<vector<string>> res;
     vector<bool> visited(n);
     //for all objects
     for(int i = 0; i < n; i++){
          if(!visited[i]){
               c++;
               vector<string> ans;
               dfs(A,i,n,ans,m,visited);
               res.push_back(ans);
               ans.clear();
          }
     }
     return res;
}
 
 /* Tested.
  * Time complexity: O(n) since it visits each node only once.
  * Space complexity: O(max(n,2m))
  */
