/* Given a graph with a start node, can it be 2-colored? 2-colored means being able to color the nodes with one of the 2 colors and not having adjacent same colors. */

// bfs - check for children being uncolored or being colored differently. If they are colored the same, there is a uncolorable cycle - return false
#include<iostream>
using namespace std;
// already implemented
vector<Node *> getNeighbors();
int getColor();
void setColor(int c);

bool is2Colorable(Node *start) {
    if(!start) return false;
    queue<Node *> q;
    q.push(start);

    while(!q.empty()) {
        Node *t = q.front();
        q.pop();
        //for start node
        if(t.getColor() == 0) {
            t.setColor(1);
        }
        //current color
        int color = t.getColor();
        vector<Node *> children = t.getChildren();
        for(Node *c : children){
            //if child has already been seen and is of the same color
            if(c.getColor() == color) {
                return false;
            } else if (c.getColor() == 0) { //if child is uncolored
                color == 1? c.setColor(2) : c.setColor(1);
                q.push(c);
            }
            //if child is already seen and is of different color, we neglect it; don't add it to queue again (results in infinite loop)
        }
    }
    return true;
}

//dfs - note that this approach works for a forest as well. Modify bfs to work with forests by having the calling function use adjacency matrix and operate on all nodes.
bool dfs(Node *start) {
    if(start.getColor() == 0) {
        start.setColor(1);
    }
    vector<Node *> children = start.getNeighbors();
    int color = start.getColor();
    for(Node *c : children) {
        if(c.getColor() == color) {
            return false;
        }
        if(c.getColor == 0) {
            color == 1? c.setColor(2):c.setColor(1);
            return dfs(c);
        }
    }
    return true;
}
bool is2Colorable(vector<vector<int>> &A) {
    int v = A.size();

    for(int i = 0; i < n; i++) {
        if(A[i].getColor() == 0) {
            if(!dfs(A[i])){
                return false;
            }
        }
    }
    return true;
}

/* Not tested.
 * Time complexity: O(2*e) where e is the number of edges
 * Space complexity: O(n) where n is the number of vertices
 */
