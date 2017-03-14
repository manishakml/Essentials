/* LC 102
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

 * return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
*/

#include<iostream>
#include<queue>
using namespace std;

vector<vector<int>> level_order(Node *r) {
  vector<vector<int>> res;
  if(!r) return res;
  vector<int> ans;
  queue<Node *> q;
  q.push(r);
  int ncl = 1, nnl = 0;
  while(!q.empty()) {
    Node *t = q.front();
    q.pop();
    ans.push_back(t->val);
    ncl--;
    if(t->l) {q.push(t->l); nnl++;}
    if(t->r) {q.push(t->r); nnl++;}
    if(ncl == 0) {
      ncl = nnl;
      nnl = 0;
      res.push_back(ans);
      ans.clear();
    }
  }
  return res;
}

/* Tested.
 * Time complexity: O(n) where n is the number of nodes.
 * Space complexity: O(n).
 */

