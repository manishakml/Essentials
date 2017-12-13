/* Given an N-ary tree and an integer n, compact the tree such that the new tree has 0 or n children with the exception of one node which can have any number of children from 0 to n. Note: If a is a an ancestor of b in original, a should remain ancestor or sibling of b in the new tree. a cannot become a child of b. */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//already given
Node {
    int val;
    vector<Node *children> children;
};
void addChild(Node *root, Node *child);

Node *compact(Node *root, int n){
    if(!root) return NULL;
    queue<Node *> q1;
    queue<Node *> q2;

    q1.push(root);
//q1 does bfs to original tree
    while(!q1.empty()){
        Node *tmp = q1.front();
        q1.pop();
        for(const Node* c : tmp->children){
            q1.push(c);
        }
        tmp->children.clear();
        //from 2nd node onwards...
        if(!q2.empty()){
        //if the node in question is going to make the parent's children count exceed n, pop the parent
            if(q2.front()->children.size() == n){
                q2.pop();
            }
            //add it as a child to the previously added node if that has < n children
            addChild(q2.front(), tmp);
        }
        //add the node to q2
        q2.push(tmp);
    }
    return root;
}

/* Not tested.
 * Time complexity: O(m * O(addChild)) where m is the total number of nodes.
 * Space complexity: O(m);
 */
