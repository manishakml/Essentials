/* Define BST. Implement basic functions on it. */

typedef struct Node {
  int val;
  struct Node* left;
  struct Node* right;
  //struct Node* parent;    *can exist*
}Node;

Node* newNode(int key) {
  Node *newN = (Node*)malloc(sizeof(Node));
  newN->val = key;
  newN->left = NULL;
  newN->right = NULL;
}

Node* insert(Node* root, int key) {
 // recursive, not taking parent into account
  if(!root) return newNode(key);
  if(key < root->val) root->left = insert(root->left,key)
  else root->right = insert(root->right,key);
  //if we do not allow duplicates, we use else if(key > root->val) for the else condition above.
  
  //iterative
  Node * newN = newNode(key);
  if(!root) return newN;
  Node* cur = root;
  Node * parent = NULL;
  
  while(cur) {
    parent = cur;
    if(key < cur->val) cur = cur->left;
    else cur = cur->right;
  }
  newN->parent = parent;
  if(!parent) root = newN;
  if(key < parent->val) parent->left = newN;
  else parent->right = newN;
  return root;
}

Node* search(Node* root, int key) {
  if(!root || root->val == key) return root;
  if(key < root->val) return search(root->left,key);
  else return search(root->right,key);
  
  //iterative
  Node *cur = root;
  while(cur) {
    if(cur->val == key) return cur;
    else if(cur->val > key) cur = cur->left;
    else cur = cur->right;
  }
  return NULL;
}

Node* findmin(Node *root) {
  if(!root) return NULL;
  Node* cur = root;
  while(cur->left) {
    cur = cur->left;
  }
  return cur;
}

Node* delete(Node* root, int key) {
  if(!root) return NULL;
  
  if(key < root->val)
    root->left = delete(root->left,key);
  else if(key > root->val) 
    root->right = delete(root->right,key);
  else {
    if(!root->left) {
      Node* tmp = root->right;
      free(root);
      return tmp;
    }
    if(!root->right) {
      Node* tmp = root->left;
      free(root);
      return tmp;
    }
    Node *tmp = findmin(root->right);
    root->val = tmp->val;
    root->right = delete(root->right,tmp->val);
  }
  return root;
}

/* Not tested.
 * Time complexity: O(h) where h is height of tree. (For insert,search and delete). Height is log(no_of_nodes). In worst case, the tree can be skewed and complexity is O(n) where n is the number of nodes in the tree.
 * Space complexity: O(h) for recursion. O(1) otherwise.
 */
