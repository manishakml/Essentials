/* LC 257
 *  Given a binary tree, return all root-to-leaf paths.
 * For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void helper(Node* root, vector<string>& res, string ans) {
  if(!root->left && !root->right) {
    res.push_back(ans);
    return;
  }
  if(root->left) helper(root->left, res, ans+"->"+to_string(root->left->val));
  if(root->right)helper(root->right, res, ans+"->"+to_string(root->right->val));
}

vector<string> r2lp(Node* root) {
  vector<string> res;
  if(!root) return res;
  helper(root, res, to_string(root->val));
  return res;
}

/* Tested.
 * Time complexity: O(n) where n is the number of nodes.
 * Space complexity: O(n) for the call stack
 */
