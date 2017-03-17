/* LC 56
 * Given a collection of intervals, merge all overlapping intervals.
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18]. 
 */

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<Interval> merge(vector<Interval>& A) {
  int n = A.size();
  vector<Interval> res;
  if(n==0) return res;
  sort(A.begin(),A.end(),[](Interval a, Interval b){return a.start < b.start};);
  res.push_back(A[0]);
  for(int i = 1; i < n; i++) {
    if(A[i].start <= res.back().end) {
      res.back().end = max(res.back.end(),A[i].end);
    } else {
      res.push_back(A[i]);
    }
  }
  return res;
}

/* Tested.
 * Time complexity: O(nlogn) where n is the number of intervals un-merged (nlogn due to sorting)
 * Space complexity: O(1) without including the space for the output.
 */
