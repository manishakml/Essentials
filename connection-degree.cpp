/* Given a vertex and a list of vertices it is connected to and given 2 vertices, find if they are 1) 1st degree connections, 2) second degree connections and 3) third degree connections. */

class Graph {
unordered_set<int> connections(int v);
};

bool 1stdegree(int a, int b) {
  return connections(a).count(b);
}

bool intersect(unordered_set<int> &a, unordered_set<int> &b){
  unordered_set<int> *smaller = a.size()<b.size()?&a:&b;
  unordered_set<int> *larger = a.size()<b.size()?&b:&a;
  
  for(auto i : smaller) {
    if(larger.count(*i)){
      return true;
    }
  }
  return false;
}
bool 2nddegree(int a, int b) {
  return intersect(connections(a), connections(b));
}

bool 3rddegree(int a, int b){
  unordered_set<int> A = connections(a);
  unordered_set<int> B = connections(b);
  
  unordered_set<int> *smaller = A.size()<B.size()?&A:&B;
  unordered_set<int> *larger = A.size()<B.size()?&B:&A;
  
  for(auto i : smaller){
      if (intersect(connections(*i), larger)){
        return true;
      }  
  }
  return false;
}

/* Not tested.
 * Time complexity: O(1), O(n), O(n*n)
 * Space complexity: O(1)
 */

