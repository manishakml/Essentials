/* Similar to LC 373
 * Given 2 arrays and k, find the first k pairs with the smallest product. The pair should have first element from array1 and second from array2.
 */
 #include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


vector<pair<int,int> >k_smallest(vector<int> &A, vector<int>& B, int k) {
    vector<pair<int,int> > res;
    if(A.size() == 0 || B.size() == 0 || k == 0) return res;
 //sort based on product. Use '>' since min_heap uses greater()
    auto cmp = [&A,&B](pair<int,int> a, pair<int,int> b){return A[a.first]*B[a.second] > A[b.first]*B[b.second];};
    priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(cmp)> min_heap(cmp);
 //Pair all elements of A with first element of B until heap is k size or all A elements are exhausted.
    for(int i = 0; i < min(k,(int)A.size()); i++) {
        min_heap.push(make_pair(i,0));
    }
    while(res.size() < k && !min_heap.empty()){
        pair<int,int> p = min_heap.top();
     //A[0],B[0] is guaranteed to be part of the result. For future comparisons, we push more elements in order
        res.push_back(p);
        min_heap.pop();
        if(p.second < B.size()-1) {
            min_heap.push(make_pair(p.first,p.second+1));
        }
    }
    return res;
}

int main() {
    vector<pair<int,int> >res;
    int n,m,k;
    cout << "\nEnter n:";
    cin >> n;
    cout << "\nEnter m:";
    cin >> m;
    vector<int> A(n);
    vector<int> B(m);
    cout << "\nEnter A of size n:\n";
    for(int i = 0; i<n; i++) {
        cin >> A[i];
    }
    cout << "\nEnter B of size m:\n";
    for(int i = 0; i<m; i++) {
        cin >> B[i];
    }
    cout << "\nEnter k:";
    cin >> k;
    res = k_smallest(A,B,k);
    for(int i = 0; i < res.size(); i++) {
        cout << endl << res[i].first << " " << res[i].second;
    }
    return 0;
}

/* Not tested thoroughly.
 * Time complexity: O(nm)
 * Space complexity: O(k)
 */
