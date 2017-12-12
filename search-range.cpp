/* LC 34
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4]. 
 */
#include<iostream>
using namespace std;

int first(vector<int>& A, int k) {
  int l = 0, r = A.size()-1, m = 0;
  while(l <= r) {
    m = l + ((r-l)>>1);
    if((m==0||A[m-1]<k) && A[m]==k){
      return m;
    } else if(A[m] < k) { // we are looking for the first occurence; so, we have to be specific about l
      l = m+1;
    } else {
      r = m-1;
    }
  }
  return -1;
}

int last(vector<int>& A, int k) {
  int l = 0, n = A.size(), r = n-1, m = 0;
  while(l <= r) {
    m = l + ((r-l)>>1);
    if((m==n-1||A[m+1]>k) && A[m]==k){
      return m;
    } else if(A[m] > k) { //we are looking for last occuenrece; so be specific about r
      r = m-1;
    } else {
      l = m+1;
    }
  }
  return -1;
}
vector<int> search(vector<int>& A, int k) {
  vector<int> res = {first(A,k), last(A,k)};
  return res;
}

/* Tested.
 * Time complexity: O(log n) where n is the number of elements.
 * Space complexity: O(1).
 */
