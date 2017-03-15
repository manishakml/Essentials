/* LC 104
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#include<iostream>
using namespace std;

int depth(Node *root) {
  return root? 1+ max(depth(root->left), depth(root->right)) : 0;
}

/* Tested.
 * Note: Iterative is similar to level order traversal where you keep track of count instead of printing/storing nodes.
 * Time complexity: O(n) where n is the number of nodes.
 * Space complexity: O(n).
 */
