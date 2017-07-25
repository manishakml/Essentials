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
  if(!root) return "# ";   //Note the space after # which is required for stringstream as a splitter.
  return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
 }

//serialize after converting to ostringstream
void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }
string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
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
                                                  
                                                  
//Using istream and ostream - untested
int main() {
        Node* root = new Node(5);
        root->left = new Node(6);
        root->left->left = new Node(7);
        root->right = new Node(8);
        root->right->right = new Node(9);
        root->right->left = new Node(10);
        print(root);
    
    //Note how ostream/istream are initialized with filebuf
        filebuf fb;
        fb.open("abc",ios::out);
        ostream os(&fb);
        ser(os,root);
        fb.open("abc",ios::in);
        istream in(&fb);
        Node* res = des(in);
        print(res);
        return 1;
}
void ser(ostream& os, Node* root) {
        if(!root) os << "# ";
        else {
                os << root->val;
                os << ' ';
                ser(os,root->left);
                ser(os,root->right);
        }
}
Node *des(istream& is) {
    //adapting to stringstream logic
        ostringstream os;
        os  << is.rdbuf();
        istringstream in(os.str());
        string val;
        in >> val;
        if(val == "#") return nullptr;
        Node* root = new Node(stoi(val));
        root->left = des(in);
        root->right = des(in);
        return root;
}
 
 /* Tested.
  * Time complexity: O(n)
  * Space complexity: O(n)
  */
