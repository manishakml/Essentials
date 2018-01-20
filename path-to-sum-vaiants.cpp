/* bt - path to sum variants */
//is there a path to any node that sums to target
bool has_path_sum(Node *root, int target){
        if(root == nullptr){
                return false;
        }
        if(root->val == target){
                return true;
        }
        return has_path_sum(root->left,target-root->val) || has_path_sum(root->right,target-root->val);
}

//is there a path to a leaf that sums to a target
bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

//find all paths from root to leaf with given sum
void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (node == nullptr) return;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr  && sum == node->val)
            paths.push_back(path);
        findPaths(node->left, sum-node->val, path, paths);
        findPaths(node->right, sum-node->val, path, paths);
        path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;
}

//find all paths from root with given sum
void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (node == nullptr) return;
        path.push_back(node->val);
        if (sum == node->val)
            paths.push_back(path);
        findPaths(node->left, sum-node->val, path, paths);
        findPaths(node->right, sum-node->val, path, paths);
        path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;
}

//find a path to leaf with the sum
void findPath(TreeNode* node, int sum, vector<int>& path) {
        if (node == nullptr) return;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr  && sum == node->val)
            return);
        findPaths(node->left, sum-node->val, path);
        findPaths(node->right, sum-node->val, path);
        path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        findPath(root, sum, path);
        return path;
}

//find a path with the sum
void findPath(TreeNode* node, int sum, vector<int>& path) {
        if (node == nullptr) return;
        path.push_back(node->val);
        if (sum == node->val)
            return);
        findPaths(node->left, sum-node->val, path);
        findPaths(node->right, sum-node->val, path);
        path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        findPath(root, sum, path);
        return path;
}
