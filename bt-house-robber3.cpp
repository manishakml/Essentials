/* LC 337
 *  The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
 * Example 1:

     3
    / \
   2   3
    \   \ 
     3   1

 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * Example 2:

     3
    / \
   4   5
  / \   \ 
 1   3   1

* Maximum amount of money the thief can rob = 4 + 5 = 9. 
*/

#include<iostream>
using namespace std;

pair<int,int> helper(Node *r) {
  pair<int,int> res;
  if(!r) return res;
  
  pair<int,int> l = helper(r->l);
  pair<int,int> r = helper(r->r);
  
  res.first = max(l.first,l.second) + max(r.first,r.second);
  res.second = r->val + l.first + r.first;
  return res;
}

int rob(Node *r) {
  pair<int,int> p = helper(r);
  return max(p.first,p.second);
}

/* Tested.
 * Note: Go through https://discuss.leetcode.com/topic/39834/step-by-step-tackling-of-the-problem/61 for good explanation.
 * Time complexity: O(n) where n is the number of houses.
 * Space complaxity: O(n) for call stack.
 */
