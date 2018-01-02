/* Write a method to add an interval (use any data structure to store) and get the total covered length.
 * To be clarified at the outset: What time complexities and space complexities are expected? What is the use-case? Will add be called more frequently than get? The design choices revolve around answers to these questions.
 */
 
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;

//Approach 1: Add all points that cover all intervals and return just the size of the set.
class Solution {
unordered_set<int> res_set;
public:
void add(int f, int t) {
        for(int i = f; i < t; i++) {
                res_set.insert(i);
        }
}

int get() {
        return res_set.size();
}
};
int main() {
        Solution s;
        s.add(1,100000);
        cout << s.get();
        return 1;
}

//Approach 2 - cannot use min_heap because, in order to merge, we empty the min_heap. std::set solves this. Consider the sequence add(),add(),get(),add(),get(). The last get() should give the total length considering all previous adds. But in approach 2, we will reset after the first get() since the min_heap will be empty during its merge().
set<pair<int,int>> s;
void add(int f, int t) {
        s.push(make_pair(f,t));
}
void merge(vector<pair<int,int>> &res) {
        if(s.empty()) return;
        auto it = s.begin();
        res.push_back(*it);
        it++;

        for(; it != s.end(); it++){
                pair<int,int> p = *it;
                if(p.first <= res.back().second){
                        res.back().second = max(res.back().second, p.second);
                } else {
                        res.push_back(p);
                }
        }
}
int get() {
        vector<pair<int,int>> res;
        merge(res);
        int len = 0;
        for(int i = 0; i < res.size(); i++) {
                len += res[i].second - res[i].first;
        }
        return len;
}
//Note: If we add merge() in add() instead of get(), we have to keep res vector global.


/* Not tested thoroughly.
 * Have timed on my machine using $time ./a.out for both approaches.
 * If there are only few intervals but the range is very high, approach 1 does not make sense and vice versa.
 * Explain the table of complexities for add and get and tradeoffs: 
 * Add     |    Get       | Approach
 * O(lgn)       O(n)        Approach 2
 * O(n)         O(1)        Approach 2 (merge in add and updateGloballen in add, return Globallen in get)
 * O(1)         O(nlgn)     push into vector in add, sort/merge/getlen in get
 * O(pts)       O(1)        Approach 1
 * Time complexity of Approach 1: O(total points in all range of all intervals) i.e., O(sum of total coverage length of all intervals)
 * Time complexity of Approach 2: If merge is part of get(), get = O(n) and add = O(log n). If merge is part of add(), add = O(n) (can be optimized to log n))and get = O(n)
 * Space complexity: O(sum of lengths of all interval ranges) for Approach 1, O(no_of_intervals) for Approach 2.
 */
