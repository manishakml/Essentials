/* LC 156
 *  Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
 * For example:
 * Given a binary tree {1,2,3,4,5},
 *     1
 *    / \
 *   2   3
 *  / \
 * 4   5
 * return the root of the binary tree [4,5,2,#,#,3,1].
 *   4
 *  / \
 * 5   2
 *    / \
 *   3   1  
 */
 
 #include <iostream>
 using namespace std;
 
 Node *upside_down(Node *root) {
  if (!root || !root->left) {
    return root;
  }
  
  Node *cur_left = root->left;
  Node *cur_right = root->right;
  Node *newroot = upside_down(root->left);
  cur_left->right = root;
  cur_left->left = cur_right;
  root->left = nullptr;
  root->right = nullptr;
  return newroot;
 }
 
 //iterative
 Node *upside_down(Node *root) {
  Node *cur = root;
  Node *prev = nullptr;
  Node *next = nullptr;
  Node *temp = nullptr;
  
  while(cur) {
    next = cur->left;
    cur->left = temp;
    temp = cur->right;
    cur->right = prev;
    prev = cur;
    cur = next;
  }
  return prev;
 }

/* Tested.
 * Note: Refer to: https://discuss.leetcode.com/topic/40924/java-recursive-o-logn-space-and-iterative-solutions-o-1-space-with-explanation-and-figure. Refer to solutions tab for the pictures.
 * Note: Follow-up: to detect if all right nodes are leaf/empty: Iterate through the left nodes, each time checking that right node 1)either does not exist or 2) exists && has a sibling && has no children.
 * Time complexity: O(n) where n is the number of nodes.
 * Space complexity: O(n) for the call stack if recursive, O(1) otherwise.
 */
