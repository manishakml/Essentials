/* LC 230
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * Note:
 * You may assume k is always valid, 1 ? k ? BST's total elements.
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */
 
 #include<iostream>
 using namespace std;
 
 //Approach 1 - using inorder
 int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            if(!--k) {
                break;
            }
            TreeNode*tmp = cur->right;
            while(tmp) {
                s.push(tmp);
                tmp = tmp->left;
            }
        }
        return cur?cur->val:NULL;
    }

//Optimization: Add an lcount (number of left children count) for each node, during insertion. kthsmallest becomes very simple then.

    
    /* Tested.
     * Time complexity: O(n) where n is the number of nodes
     * Space complexity: O(n)
     */
