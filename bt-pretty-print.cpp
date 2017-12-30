/* Print a binary tree. Need not print the edges, but print spaces well.
 * for example, print Trees like:
 *
 *        1          
 *       / \       
 *      2   3        
 *     /
 *    4
 *   / \
 *  5   6
 *
 * into these:
 *
 *      1          
 *     2 3       
 *   4 
 *  5 6
 */
 
 #include<iostream>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

typedef struct Node {
        int val;
        struct Node * left;
        struct Node* right;
}Node;

class Solution {
unordered_map<Node*, int> m;

public:
Node* newNode(int k) {
        Node* newN = (Node*)malloc(sizeof(Node));
        newN->val = k;
        newN->left = NULL;
        newN->right = NULL;
        return newN;
}
void inorder(Node *root) {
        stack<Node *> s;
        Node *cur = root;
        while(cur) {
                s.push(cur);
                cur = cur->left;
        }
        int k = 0;
        while(!s.empty()) {
                Node* t = s.top();
                s.pop();
                m[t] = k;
                k += (to_string(t->val)).size();
                if(t->right) {
                        Node *cur = t->right;
                        while(cur){
                                s.push(cur);
                                cur = cur->left;
                        }
                }
        }
 
 void print(Node* root) {
        inorder(root);
        queue<Node*> q;
        if(!root) return;
        q.push(root);
        int prev_sp = 0;
        while(!q.empty()){
                int s = q.size();
                for(int i = 0; i < s; i++) {
                        Node* t = q.front();
                        q.pop();                       
                        while(prev_sp++ < m[t]) {
                         cout << ' ';
                        }
                        cout << t->val;
                        prev_sp += (to_string(t->val)).size();
                        if(t->left) q.push(t->left);
                        if(t->right) q.push(t->right);
                }
                cout << endl;
                prev_sp = 0;
        }
}
};

int main() {
        Solution obj;
        Node* root = obj.newNode(1);
        root->left = obj.newNode(2);
        root->right = obj.newNode(3);
        root->left->left = obj.newNode(4);
        root->left->left->left = obj.newNode(5);
        root->left->left->right = obj.newNode(6);
        obj.print(root);
        return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(n) where n is the number of nodes.
 * Space complexity: O(n)
 */

