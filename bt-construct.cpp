/* LC 105
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */
 
 int find_inorder(vector<int> &inorder, int inStart, int inEnd, int val){
        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == val){
                return i;
            }
            
        }
        return 0;
    }
    
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preStart > preorder.size()-1 || inStart > inEnd) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int idx = find_inorder(inorder, inStart, inEnd, root->val);
        
        root->left = helper(preStart+1, inStart, idx-1, preorder, inorder);
        root->right = helper(preStart + (idx-inStart) + 1, idx+1, inEnd, preorder, inorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,0,inorder.size()-1,preorder,inorder);
    }
    
    /* Tested. 
     * Time complexity: O(n^2)
     * Space complexity: O(n)
     */
