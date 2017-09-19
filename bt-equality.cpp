/* LC 100
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */
 #include<iostream>
 using namespace std;
 
bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    
/* Tested.
 * Time complexity: O(n) where n is the number of nodes in the smaller tree.
 * Space complexity: O(n) for call stack
 */
