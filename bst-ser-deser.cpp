/* LC 449
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 * Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
 * The encoded string should be as compact as possible.
 * Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless. 
 */
 
 #include<iostream>
 #include<string>
 #include<stringstream>
 using namespace std;
 
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
    
    TreeNode* deserialize(istringstream &is, int lower, int upper) {
        string val;
        is >> val;
        int v = stoi(val);
        if(v < lower || v > upper) return nullptr;
        TreeNode* root = new TreeNode(v);
        root->left = deserialize(is,lower,root->val);
        root->right = deserialize(is,root->val,upper);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserialize(is, INT_MIN, INT_MAX);
    }
    
    /* Not tested - giving stoi exception
     * Note: This is similar to BT, except we do not need placeholders. We decode by position of the nodes by value-property of the BST.
     * Time complexity: O(n) where n is the number of nodes.
     * Space complexity: O(n) for the tmp string. O(1) otherwise.
     */
