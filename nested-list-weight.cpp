/**
 * Leetcode 339
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 * Example 1:
 * Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
 #include <iostream>
 #include <vector>
 using namespace std;
 
 int helper(const vector<NestedInteger> &arr, int level) {
    if (arr.size() == 0) {
       return 0;
    }
    int sum = 0;
    for(NestedInteger a : arr) {
       if (a.isInteger()) {
          sum += a.getInteger() * level;
       } else {
          sum += helper(a.getList(), level+1);
       }
    }
    return sum;
 }
 
 int getWeight(const vector<NestedInteger> &arr) {
    return helper(arr, 1);
 }
