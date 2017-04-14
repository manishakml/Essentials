/* LC 102
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
 * return its level order traversal as:
 * [
 *  [3],
 *  [9,20],
 *  [15,7]
 * ]
 */
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//Approach 1
vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        int cur_max;
        if(!root) return res;
        q.push(root);
        
        while(!q.empty()){
            cur_max = INT_MIN;
            int sz = q.size();
            
            for(int i = 0; i < sz; i++) {
                TreeNode* t = q.front();
                q.pop();
                cur_max = max(cur_max,t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(cur_max);
        }
        return res;
    }

//Approach 2
vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        int cur_max = INT_MIN, ncl = 1, nnl=0;
        if(!root) return res;
        q.push(root);
        
        while(!q.empty()){
            
            
                TreeNode* t = q.front();
                q.pop();
                ncl--;
                cur_max = max(cur_max,t->val);
                if(t->left) {q.push(t->left);nnl++;}
                if(t->right) {q.push(t->right);nnl++;}
                
                if(!ncl) {
                        ncl = nnl;
                        nnl=0;
                        res.push_back(cur_max);
                        cur_max = INT_MIN;
                }    
        }
        return res;
    }

/* Tested.
 * Time complexity: O(n) where n is the number of nodes.
 * Space complexity: O(n).
 */

