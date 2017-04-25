/* LC Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 */
 
 #include<iostream>
 using namespace std;

//Note: This soln. assumes that the nodes are present in the tree.
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        return !l ? r : !r ? l : root;
}

//This soln. works even if nodes are not present in the tree.
TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, bool& v1, bool& v2) {
        if(!root) return nullptr;
        if(root == p) {
            v1 = true;
            return root;
        }
        if(root == q) {
            v2 = true;
            return root;
        }
        
        TreeNode* l = helper(root->left,p,q,v1,v2);
        TreeNode* r = helper(root->right,p,q,v1,v2);
        
        if(l&&r) return root;
        return l?l:r;
    }
    
    bool find(TreeNode* root, TreeNode* p) {
        if(!root) return false;
        
        if(root == p || find(root->left,p) || find(root->right,p)) {
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool v1 = false, v2 = false;
        TreeNode *lca = helper(root,p,q,v1,v2);
        //if(p&q are on either sides || if q is on right and p is in its subtree || if p is on left and q is in its subtree)
        if(v1 && v2 || v2&&find(root,p) || v1&&find(root,q)) {
            return lca;
        }
        //either or both nodes not present
        return nullptr;
    }
    
    /* Tested.
     * Time complexity: O(n) where n is the number of nodes in the tree.
     * Space complexity: O(n) for call stack.
     */
