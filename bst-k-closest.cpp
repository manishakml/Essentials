/* LC 272
 * Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 * Note:
 * Given target value is a floating point.
 * You may assume k is always valid, that is: k ≤ total nodes.
 * You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 * Follow up:
 * Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
 */
 
 void inorder(TreeNode* root, double target, queue<int>& q, int k) {
        if(!root) return;
        inorder(root->left, target, q, k);
        if(q.size() < k) q.push(root->val);
        else if (q.size() == k) {
            if(abs(root->val-target) < abs(q.front()-target)){
                q.pop();
                q.push(root->val);
            }
        }        
        inorder(root->right, target, q, k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        queue<int> q;
        inorder(root,target,q,k);
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
    
    /* Tested.
     * Note: Reason why inorder works for BST: Inorder on bst gives a sorted array. To find k val closest to x, we have to look at the neighbors of x (k times). this is optimized since we get a sorted array.
     * Time complexity: O(n)
     * Space complexity: O(k) for queue or O(log n) for call stack
     */
