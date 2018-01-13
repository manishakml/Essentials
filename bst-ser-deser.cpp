/* LC 449
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 * Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
 * The encoded string should be as compact as possible.
 * Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless. 
 */
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialize(TreeNode* root, ostringstream &os) {
        if(!root) return;
        os << to_string(root->val) << " ";
        serialize(root->left,os);
        serialize(root->right,os);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        serialize(root,os);
        return os.str();
    }

    TreeNode* deserialize(vector<int> &values, int &pos, int lower, int upper) {
        if(pos == values.size()) {
         return nullptr;
        }
        int v = values[pos];
        if(v < lower || v > upper) return nullptr;
        TreeNode* root = new TreeNode(v);
        pos++;
        if(root->val != INT_MIN){
         root->left = deserialize(values, pos, lower,root->val-1);
        } else {
         root->left = nullptr;
        }
        root->right = deserialize(values, pos ,root->val,upper);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        vector<int> values;
        string tmp;
        while(is >> tmp) {
         values.push_back(stoi(tmp));
        }
        int pos = 0;
        return deserialize(values, pos, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
    
    /* Tested.
     * Note: This is similar to BT, except we do not need placeholders. We decode by position of the nodes by value-property of the BST.
     * Note: pos is taken as reference. 
     * Note: Don't forget to handle duplicates. Handle cases of val being int_min, int_max
     * Time complexity: O(n) where n is the number of nodes.
     * Space complexity: O(n) for the tmp string. O(1) otherwise.
     */
