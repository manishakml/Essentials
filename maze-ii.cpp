/* Given a 2d grid, src and dst, grid contains walls, find the min steps to reach from src to dst. */

bool isSafe(vector<vector<int>> &A, pair<int,int> p, int m, int n){
  return (p.first >=0 && p.first < n && p.second >=0 && p.second < m && A[p.first][p.second] == 0);
}
int path(vector<vector<int>> &A, pair<int,int> &s, pair<int,int> &e){
  
  int n = A.size();
  if(n == 0){
    return -1;
  }
  int m = A[0].size();
  if(m == 0){
    return -1;
  }
  int c = 0;
  if(s == e){
    return c;
  }
  
  queue<pair<int,int>> q;
  q.push(s);
  vector<int> R = {0,1,0,-1};
  vector<int> C = {1,0,-1,0};
  
  while(!q.empty()){
    int sz = q.size();
    c++;
    for(int i = 0; i < sz; i++){
      pair<int,int> t = q.front();
      q.pop();
      A[t.first][t.second] = 1;
      for(int k = 0; k < 4; k++){
        pair<int,int> p = make_pair(t.first+R[k],t.second+C[k]);
        if(p == e){
          return c;
        }
        if(isSafe(A,p,m,n){
          q.push(p);
        }
      }
    }
  }
  return false;
}

/* Not tested.
 * Time: O(mn)
 * Space: O(mn)
 */

