/* Given an nary tree with an interface vector<Node*> getChildren(Node*>; return a list of list of nodes ordered by the time they are scraped off.
 * The requirement is to scrape the leaves at each level. Once the first level of leaves are removed, remove the second layer of leaves..until root is left (and removed).
 * The result list has the 1st list element as the first layer of leaves removed, the 2nd element as 2nd layer of leaves removed...last element as root.
 */
 
 #include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//already implemented
vector<Node *> getChildren(root);

int helper(Node *root, unordered_map<Node*,int> &m) {
    if(!root) {
        return 0;
    }
    int h = 0;
    vector<Node *> children = getChildren(root);
    for(const Node *c : children) {
        h = max(h,helper(c,m));
    }
    m[root] = 1 + h;
    return 1 + h;
}

vector<vector<Node *>> falling_leaves(Node *root) {
    unordered_map<Node*, int> m;
    int ht = helper(root,m);
    vector<vector<Node*>>(ht);

    for(const pair<Node*,int> &p : m) {
        res[p.second-1].push_back(p.first);
    }
    return res;
}

/* Hand tested.
 * Note: This is similar to calculating height of the tree. But instead, we are using a map to mark each node's level.
 * Time complexity: O(n) where n is the number of nodes.
 * Space complexity: O(n) for the levels.
 */
