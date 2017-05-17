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

// Approach 2: Use a sorted data structure for storage. Merge. Get length. Merge can be part of add or get based on the use-case.
class Solution {
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > min_heap;
vector<pair<int,int> > res;
void print(vector<pair<int,int> > A) {
        for(int i = 0; i < A.size(); i++) {
                cout << A[i].first << "," << A[i].second << endl;
        }
}
void merge() {
        if(min_heap.empty()) return;
        res.push_back(min_heap.top());
        min_heap.pop();

        while(!min_heap.empty()) {
                pair<int,int> p = min_heap.top();
                min_heap.pop();
                if(p.first <= res.back().second){
                        res.back().second = max(res.back().second, p.second);
                } else {
                        res.push_back(p);
                }

        }
}
public:
int get() {
       // vector<pair<int,int> > res = merge();
        int len = 0;
        for(int i = 0; i < res.size(); i++) {
                len += res[i].second - res[i].first;
        }
        return len;
}
void add(int f, int t) {
        min_heap.push(make_pair(f,t));
        merge();
}
};
int main() {
        Solution s;
        s.add(1,100000);
        cout << s.get();
        return 1;
}

/* Not tested thoroughly.
 * Have timed on my machine using $time ./a.out for both approaches.
 * If there are only few intervals but the range is very high, approach 1 does not make sense and vice versa.
 * Time complexity of Approach 1: O(total points in all range of all intervals) i.e., O(sum of total coverage length of all intervals)
 * Time complexity of Approach 2: If merge is part of get(), get = O(n) and add = O(log n). If merge is part of add(), add = O(n) (can be optimized to log n))and get = O(n)
 * Space complexity: O(sum of lengths of all interval ranges) for Approach 1, O(no_of_intervals) for Approach 2.
 */
