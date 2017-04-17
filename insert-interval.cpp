/* LC 57
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
 */
#include<iostream>
#include<vector>
using namespace std;

vector<Interval> insert(vector<Interval>& I, Interval ni) {
  vector<Interval> res;
  int i = 0;
  int n = I.size();
  for(;i < n; i++) {
    if(ni.e < I[i].s) break;
    else if (ni.s > I[i].e) res.push_back(I[i]);
    else {
      ni.s = min(I[i].s,ni.s);
      ni.e = max(I[i].e,ni.e);
    }
  }
  res.push_back(ni);
  for(;i<n;i++)
     res.push_back(I[i]);
  return res;
}

/* Tested.
 * Time complexity: O(n) where n is the number of intervals.
 * Space complexity: O(1) without counting the result.
 */
