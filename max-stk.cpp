/* Implement a stack-like data structure with push(), pop(), peek(), peekMax() and popMax() methods.
 * peekMax() returns the max-value element pushed so far.
 * popMax() pops the max element from the stack (might be somewhere in the middle.
 * Expected complexities: O(1) for peeks, O(log n) for others.
 */

#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

typedef struct Tnode{
    int val;
    struct Tnode* left;
    struct Tnode* right;
    struct Tnode* parent;
    struct Lnode *ptr;
}Tnode;

typedef struct Lnode{
    int val;
    struct Lnode* next;
    struct Tnode* adr;
}Lnode;

Lnode *head = NULL;
Tnode *root = NULL;
Tnode *maxNode = NULL;

//O(log n)
void push(int val) {
    Lnode* newLnode = (struct Lnode*)malloc(sizeof(struct Lnode));
    Tnode* newTnode = (struct Tnode*)malloc(sizeof(struct Tnode));
    //Creating a dummy node to handle LL deletion given the node to be deleted and the node is the last node.
    if(!head){
        Lnode* tail = (struct Lnode*)malloc(sizeof(struct Lnode));
        tail->val = INT_MIN;
        tail->next = NULL;
        tail->adr = NULL;
        head = tail;
    }
    newLnode->val = val;
    newLnode->next = head;
    head = newLnode;

    Tnode *cur = root;
    Tnode *parent = NULL;
    while(cur) {
        parent = cur;
        if(cur->val > val) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    newTnode->val = val;
    newTnode->parent = parent;
    newTnode->left = NULL;
    newTnode->right = NULL;

    newLnode->adr = newTnode;
    newTnode->ptr = newLnode;

    if(parent == NULL) {
        root = newTnode;
    }
    else if(val < parent->val){
        parent->left = newTnode;
    } else {
        parent->right = newTnode;
    }
  
    if(!maxNode || val > maxNode->val){
        maxNode = newTnode;
    }
}

//O(1)
int peek(){
    return head->val;
}

//O(1)
int peekMax(){
    if(maxNode) {
        return maxNode->val;
    }
    return INT_MIN;
}

//O(log n)
Tnode* rightMost() {
    if(!root){
        return NULL;
    }
    Tnode* cur = root;
    while(cur->right){
        cur = cur->right;
    }
    return cur;
}

//O(log n)
Tnode* minNode(Tnode* root) {
    if(!root) return NULL;
    Tnode* cur = root;
    while(cur->left) {
        cur = cur->left;
    }
    return cur;
}

//O(log n)
void deleteTNode(Tnode* node){
    if(!node) return;
    Tnode* par = node->parent;
    if(node->left == NULL) {
        Tnode* tmp = node->right;      //0 or 1 children
        //adjust parent's l/r to point to the grand child
        if(!par) {
            root = tmp;
        }
        else if(par->left == node){
            par->left = tmp;
        } else {
            par->right = tmp;
        }
        //adjust parent to grand parent
        if(tmp) {
            tmp->parent = par;
        }
        free(node);
        return;
    }
    if(node->right == NULL) {
        Tnode* tmp = node->left;      //1 child
        //adjust parent's l/r to point to the grand child
        if(!par) {
            root = tmp;
        }
        else if(par->left == node){
            par->left = tmp;
        } else {
            par->right = tmp;
        }
        //adjust parent to grand parent
        if(tmp) {
            tmp->parent = par;
        }
        free(node);
        return;
    }
    //inorder successor in case node to be deleted has 2 children
    Tnode* tmp = minNode(node->right);
    //copy inorder successor's contents to current node and adjust links
    if(tmp){
        node->val = tmp->val;
        node->ptr = tmp->ptr;
        tmp->ptr->adr = node;
    }
    deleteTNode(tmp);
}

//O(1)
void deleteLNode(Lnode* node){
    if(!node || node->next == NULL) return;
    node->val = node->next->val;
    node->adr = node->next->adr;
    node->adr->ptr = node;
    node->next = node->next->next;
    free(node->next);
}

//O(log n)
void pop(){
    if(head->next == NULL) return;
    Lnode* tmpL = head;
    head = head->next;
    Tnode *tmpT = tmpL->adr;
    if(tmpT == maxNode) {
        deleteTNode(tmpL->adr);
        maxNode = rightMost();
    } else {
        deleteTNode(tmpL->adr);
    }
    free(tmpL);
}

//O(log n)
void popMax(){
    deleteLNode(maxNode->ptr);
    deleteTNode(maxNode);
    maxNode = rightMost();
}

//cleaner approach
class MaxStack{
    std::list<int> l;   //dll
    std::set<int> s;    //rb tree - balanced
    unordered_map<int,unordered_set<list::iterator>> m; //elem to node mapping
public:
    void push(int a){
        l.push_front(a);    //O1
        s.insert(a);    //Ologn
        m[a].insert(l.begin()); //O1
    }
    void pop(int &res){
        int t = l.front();  //O1
        m[t].erase(l.begin());  //O1
        if(m[t].size() == 0){   //O1
            m.erase(t);     //O1
            s.erase(t); //Ologn
        }
        l.pop_front();  //O1
        res = t;
    }
    int peek(){
        return l.front();   //O1
    }
    int peekMax(){
        return s->rbegin();  //O1
    }
    void popmax(int &res){
        int t = s->rbegin();    //O1
        list::iterator it = m[t].begin();   //O1
        m[t].erase(it); //O1
        if(m[t].size() == 0){   //O1
            m.erase(t); //O1
            s.erase(t); //Ologn
        }
        l.erase(it);    //O1
        res = t;
    }

/* Not tested thoroughly.
 * Time complexity: As expected in the problem statement (denoted before each method)
 * Space complexity: O(n) where n is the number of elements. Note we use a LL and BST with special/extra fields.
 */
