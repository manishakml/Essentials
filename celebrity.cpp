/* LC 277
 *  Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
 * Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
 * You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.
 * Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1. 
 */
#include<iostream>
using namespace std;

int celebrity(int n) {
  int i = 0;
  //find potential celebrity
  for(int j = 1; j < n; j++) {
    if(knows(i,j))
      i=j;
  }
  //verify celebrity
  for(int j = 0; j < n; j++) {
    if(i!=j && (knows(i,j) || !knows(j,i))) return -1;
    /* The above line can be optimized to the following since one round of checks are already done in the first loop
     * if(j < i && (knows(i,j) || !knows(j,i))) return -1;
     * if(j > i && !knows(j,i)) return -1;
     */
  }
  return i;
}

/* Tested.
 * Note: How to implement knows(): Use 2d matrix if data is not huge. Use map if data is huge(since it will be sparse mostly).
 * Time complexity: O(n) assuming knows(i,j) is O(1).
 * Space complexity: O(1)
 */
