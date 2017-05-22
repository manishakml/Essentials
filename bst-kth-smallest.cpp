/* LC 230
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * Note:
 * You may assume k is always valid, 1 ? k ? BST's total elements.
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */
 
 #include<iostream>
 using namespace std;
 
 //Approach 1 - using inorder
 int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            if(!--k) {
                break;
            }
            TreeNode*tmp = cur->right;
            while(tmp) {
                s.push(tmp);
                tmp = tmp->left;
            }
        }
        return cur?cur->val:NULL;
    }

//Approach 2: Optimization: Add an lcount (number of left children count) for each node, during insertion. kthsmallest becomes very simple then.
struct Node {
      int val;
      int lcount;
      Node *left;
      Node *right;
      Node(int x) : val(x), left(NULL), right(NULL) {}
  };

Node* insert(Node* root, int key) {
  Node * newN = newNode(key);
  if(!root) return newN;
  Node* cur = root;
  Node * parent = NULL;
  
  while(cur) {
    parent = cur;
    if(key < cur->val) {cur->lcount++;cur = cur->left;}
    else cur = cur->right;
  }
  newN->parent = parent;
  if(!parent) root = newN;
  if(key < parent->val) parent->left = newN;
  else parent->right = newN;
  return root;
}

int kthSmallest(Node* root, int k) {
 Node *cur - root;
 while(cur){
  if(k == cur->lcount + 1) return cur->val;
  else if (k < cur->lcount) cur = cur->left;
  else {k = k-cur->lcount;cur = cur->right;}
 }
 return -1;
}
    /* Tested.
     * Time complexity: O(n) where n is the number of nodes for approach 1. O(log n) for approach 2
     * Space complexity: O(n)
     */
