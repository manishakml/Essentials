/* Given k sorted streams, merge into one sorted stream. */

#include<iostream>
using namespace std;

template<class T>
auto cmp = [](pair<T,int> a, pair<T,int> b){a.first > b.first;}; // '>' since min_heap uses greater()

priority_queue<pair<T,int>, vector<pair<T,int>>, decltype(cmp)> min_heap;

template<class T>
class sortedStream {
public:
        T next() = 0;
        bool hasNext() = 0;
};

template<class T>
class mergedSortedStream extends sortedStream {
public:
        mergedSortedStream(vector<sortedStream> &A){
                int k = A.size();
                for(int i = 0; i < k; i++) {
                        if(A[i].hasNext()){
                                min_heap.push(make_pair(A[i].next(),i));
                        }
                }
        }
        
        T next(){
                        pair<T,int> t = min_heap.top();
                        min_heap.pop();
                        if(A[t.second].hasNext()){
                                min_heap.push(make_pair(A[t.second].next(),t.second));
                        }
                        return t.first;
                }

                bool hasNext(){
                        return !min_heap.empty();
                }
};

template<class T>
sortedStream<T> merge(vector<sortedStream<T>> &A) {
        mergedSortedStream m(A);        
        return m;
}

/* Not tested.
 * Need to work on follow-up
 * Time complexity: O(knlogk)
 * Space complexity: O(k)
 */
