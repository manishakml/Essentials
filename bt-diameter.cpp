/* LC 543
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 * Example:
 * Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * Note: The length of path between two nodes is represented by the number of edges between them.
 */

#include<iostream>
using namespace std;

int height(TreeNode *root) {
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        
        return max(lh+rh, max(ld,rd));
    }

/* Tested.
 * Note: If diameter is defined by number of nodes rather than number of edges, the only change will be in the last line 'return max(lh+rh+1, max(ld,rd));'
 * Time complexity: O(n) where n is the number of nodes.
 * Space complexity: O(n) for the call stack.
 */
