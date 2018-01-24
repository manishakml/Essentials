/* Given a special tree with root's value being the lesser of its childresns' values and a node has either 0 or 2 children, find the 2nd min. */

/*
A tournament tree can be in one of the 2 forms:
        2
    2      3
4     2  5    3

or
        2
    2      4
2     3  4   5
The trick is to identify that sibling is a potential solution or the only other (min) solution can exist in the subtree with the root's value (coz the sibling is greater and hence, all the sibling's children are greater)
*/

void 2ndSmallest_helper(Node *root, int &res){
        if(root == nullptr || root->left == nullptr || root->right == nullptr){
                return;
        }
        if(root->left->val == root->val){
                res = min(res,root->right->val);
                2ndSmallest_helper(root->left,res);
        } else {        //root->right->val == root->val
                res = min(res,root->left->val);
                2ndSmallest_helper(root->right,res);
        }

}
int 2ndSmallest(Node *root){
        int res = INT_MAX;
        2ndSmallest_helper(root, res);
        return res;
}

/* Not tested.
 * Note: If kth smallest is needed, upto k times, delete the minimum. This is O(log(h)).
 * Time: O(h)
 * Space: O(h)
 */
