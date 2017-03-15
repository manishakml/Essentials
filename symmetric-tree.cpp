/* LC 101
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
 */
 
 #include<iostream>
 using namespace std;
 
 bool isSym(TreeNode *r1, TreeNode *r2) {
        if(!r1 && !r2) return true;
        return r1 && r2 && r1->val == r2->val && isSym(r1->left, r2->right) && isSym(r1->right, r2->left);
 }
 bool isSymmetric(TreeNode* root) {
        return isSym(root,root);
 }
 
 /* Tested.
  * Time complexity: O(n) where n is the number of nodes.
  * Space complexity: O(n).
  */
