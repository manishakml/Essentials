/* LC 235
 *  Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 */

#include<iostream>
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(p->val < root->val && q->val < root->val)
          return lowestCommonAncestor(root->left,p,q);
        else if(p->val > root->val && q->val > root->val)
          return lowestCommonAncestor(root->right,p,q);
        return root;
}

//iterative
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if(p->val < root->val && q->val < root->val)
                root=root->left;
            else if(p->val > root->val && q->val > root->val)
                root=root->right;
            else
                break;
        }
        return root;
    }
// approach 3
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        while((root->val-p->val) * (root->val-q->val) > 0) {
            root= (root->val>p->val)?root->left:root->right;
        }
        return root;
    }

/* Tested.
 * Time complexity: O(log n) where n is the number of nodes.
 * Space complexity: O(log n) for the call stack, O(1) otherwise.
 */
