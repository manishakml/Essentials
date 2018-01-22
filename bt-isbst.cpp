/* LC 98
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode *root, int l , int h){
        if(!root){
            return true;
        }
        if(root->val < l || root->val > h){
            return false;
        }
        
        if(root->val == INT_MIN){
            return root->left == nullptr && helper(root->right,root->val+1,h);
        } else if (root->val == INT_MAX){
            return root->right == nullptr && helper(root->left,l,root->val-1);
        } else {
            return helper(root->left,l,root->val-1) && helper(root->right,root->val+1,h);    
        }
        
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root,INT_MIN,INT_MAX);
    }
};

/* Tested.
 * Time: O(n)
 * Space: O(ht. of tree)
 */
