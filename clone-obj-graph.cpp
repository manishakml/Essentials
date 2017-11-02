/* Given an object graph (Single root, multiple children, directed graph, can contain cycles), clone it.
 * Assume these are implemented:
 * Node * copyNode(Node *root);
 * vector<Node *> getChildren(Node *root);
 * int getNumberOfParents(Node *root);
 * void addChild(Node *child, Node *root);
 */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef struct Node {
    int val;
    vector<struct Node*> children;
};

Node * copyNode(Node *root);
vector<Node *> getChildren(Node *root);
int getNumberOfParents(Node *root);
void addChild(Node *child, Node *root);

//bfs from root
Node *clone(Node *root){
    queue<Node *> q;
    unordered_map<Node *, Node *> m;
    if(!root) return NULL;
    Node *newRoot;
    q.push(root);

    //create clones, don't connect yet
    while(!q.empty()){
        Node *t = q.front();
        q.pop();
        //a node can be reached from many parents, avoid storing/cloning them again by using the map check ---(1)
        if(m.find(t) == m.end()){
            Node *clone = copyNode(t);
            m[t] = clone;
            vector<Node *> children = getChildren(t);
            for(Node *c : children){
                q.push(c);
            }
            if(t == root){
                newRoot = t;
            }
        }
    }
    
    //connect the clone graph
    for(pair<Node*,Node*> &p: m){
        vector<Node*> children = getChildren(p.first);
        for(auto c: children){
            addChild(m[c],p.second);
        }
    }
    return newRoot;
}

/* Hand-tested for DAG and cycles.
 * Time complexity: O(n)
 * Space complexity: O(n). Space has been optimized by the map check in (1). It is still linear though.
 */ 

