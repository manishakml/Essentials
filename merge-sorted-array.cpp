/* LC 88
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 */
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n) {
  int w = m+n-1, i = m-1, j = n-1;
  while(j >= 0) {
    A[w--] = (i >= 0 && A[i] > B[j])?A[i--]:B[j--];
  }
}

/* Tested.
 * Time complexity: O(m+n)
 * Space complexity: O(1)
 */
