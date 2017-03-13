/* LC 297
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 * Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 * For example, you may serialize the following tree
    1
   / \
  2   3
     / \
    4   5
 * as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
 * Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless. 
 */
 
 #include<iostream>
 #include<sstream>
 using namespace std;
 
//recursive (preorder)
 string serialize(Node *root) {
  if(!root) return "# "   //Note the space after # which is required for stringstream as a splitter.
  return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
 }
 
 Node *deserialize(istringstream& in) {
  string val;
  in >> val;
  if(val == "#") {
    return nullptr;
  }
  Node *root = new Node(stoi(val));
  root->left = deserialize(in);
  root->right = deserialize(in);
  return root;
 }
 
 Node *deserialize(string s) {
  istringstream in(s);
  return deserialize(in);
 }

//iterative (level order)
string serialize(Node *root) {
    queue<Node *> q;
    string res = "";
    
    q.push(root);
    
    while(!q.empty) {
        Node *t = q.front();
        q.pop();
        res += t? to_string(t->val) : "#";
        res += " ";         //Note the space needed by stringstream
        if(t) {
            q.push(t->left);
            q.push(t->right);
        }
    }
    return res;
}

Node *deserialize(string s) {
    istringstream in(s);
    string val;
    in >> val;
    queue<Node *> q;
    Node *root = (val == "#")? nullptr : new Node(stoi(val);
    q.push(root);   
    while(!q.empty()) {
        int sz = q.size();
        for(int i=0; i < sz; i++) {
            Node *t = q.front();
            q.pop();
            if(t) {
                in >> val;
                t->left = (val == "#")? nullptr : new Node(stoi(val));
                in >> val;
                t->right = (val == "#")? nullptr : new Node(stoi(val));
                q.push(t->left);
                q.push(t->right);
            }
        }
    }
    return root;                                  
}
 
 /* Tested.
  * Time complexity: O(n)
  * Space complexity: O(n)
  */
