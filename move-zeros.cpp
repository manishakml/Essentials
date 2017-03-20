/* LC 283
 *  Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 * Note:
 *     You must do this in-place without making a copy of the array.
 *     Minimize the total number of operations.
 */

#include<iostream>
#include<vector>
using namespace std;

void move(vector<int>& A) {
  int r = 0, w = 0, n = nums.size();
  while(r<n) {
    A[r]?A[w++]=A[r++]:r++;
  }
  while(w<n) {
    A[w++] = 0;
  }
}

//Another implementation
void move(vector<int>& A) {
  int j = 0;
  for(int i = 0; i < A.size(); i++) {
    if(A[i]) {
      swap(A[i],A[j++]);
    }
  }
}
