/* LC 366 
 * Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
 *         1
 *        / \
 *       2   3
 *      / \
 *     4   5
 * Return: [[4,5,3], [2], [1]]
 */
 
 #include<iostream>
 #include <vector>
 using namespace std;
 
 int helper(Node *root, vector<vector<int>>& res) {
    if(!root) return 0;
    int level = max(helper(root->left,res), helper(root->right,res)) + 1;
    if(level > (int)res.size()) res.push_back(vector<int>());
    res[level-1].push_back(root->val);
    return level;
 }
 
 vector<vector<int>> collectLeaves(Node *root) {
    vector<vector<int>> res;
    helper(root, res);
    return res;
 }

//approach for n-ary tree with getChildren() and return expected as vector<unordered_set>
int helper(Node *root, vector<unordered_set<int>>& res) {
    if(!root) return 0;
    int level = 0;
    for(auto c : root->getChildren()){
     level = max(level, helper(c,res));
    }
    if(level == (int)res.size()) res.push_back(unordered_set<int>());
    res[level].push_back(root->val);
    return level+1;
 }
 
 vector<unordered_set<int>> collectLeaves(Node *root) {
    vector<unordered_set<int>> res;
    helper(root, res);
    return res;
 }
 
 /* Tested
  * Time complexity: O(n) where n is the number of nodes in the tree.
  * Space complexity: O(n) for the call stack, O(n) for the result.
  */
