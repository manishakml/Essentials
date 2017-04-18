/* LC 103
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        
        bool flag = true;
        
        while(!q.empty()) {
            int sz = q.size();
            vector<int> ans(sz);
            for(int i = 0; i < sz; i++) {
                TreeNode* t = q.front();
                q.pop();
                int idx = flag?i:sz-i-1;
                ans[idx] = t->val;
            
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            if(!ans.empty()) res.push_back(ans);
            flag = !flag;
          
        }
        return res;
    }

/* Tested.
 * Time complexity: O(n) where n is the number of nodes.
 * Space complexity: O(1)
 */
