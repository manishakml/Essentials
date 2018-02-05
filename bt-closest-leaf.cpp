/* LC 742
 * Given a bt and a value of a node, find the closest leaf to that node. */
 void build_graph(Node* root, Node *parent, unordered_map<Node*,vector<Node*>> &m, Node* start, int k){
  if(!root) {
    return;
  }
  if(root->val == k){
    start = root;
  }
    
  if(parent){
      m[root].push_back(parent);
      m[parent].push_back(root);
  }
  build_graph(root->left, root, m, start, k);
  build_graph(root->right, root, m, start, k);
 }
 
 int find_closest_leaf(Node* root, int k){
 if(!root) return 0;
  unordered_map<Node*, vector<Node*>> m;
  //each node can be treated as a node in the graph with 3 edges - right, left and parent. Build that graph.
  build_graph(root,nullptr,m, start, k);
  //do a bfs on the graph. bfs gives the shortest path
  unordered_set<Node*> discard;
 queue<Node*> q;
 q.push(start);
 while(!q.empty()){
  Node* t = q.front();
  q.pop();
  discard.insert(t);
  if(t->left == nullptr && t->right == nullptr){
    return t->val;
  }
  for(auto n : m[t]){
    if(!discard.count(n))
      q.push(n);
  }
 }
 return 0;
 }
 
 /* Not tested.
  * Time: O(n)
  * Space: O(n)
  */
