/* Given a stream of integers, find the top k integers. 2 variations: 1)duplicates are allowed in the result, 2) duplicates are not allowed.
 * Eg., Stream: 3,3,3,1,1,1,2,2,2,... Top 3 elements in (1) 3,3,3. Top 3 elements in (2) 3,2,1.
 */
 
 #include<iostream>
using namespace std;

//duplicates allowed in result
template<class T>
class TopK1{
priority_queue<T, vector<T>, std::greater()> min_heap;
int k;
public:
void add(T a){
    if(k <= 0) {
        return;
    }
    if(min_heap.size() >= k && a < min_heap.top()){
        return;
    }
    if(min_heap.push(a) && min_heap.size() > k) {
        min_heap.pop();
    }
}

vector<T> getK(){
    vector<T> res;
    while(!min_heap.empty()){
        res.push_back(min_heap.top());
        min_heap.pop();
    }
    return res;
}
};
//duplicates not allowed in result
template<class T>
class TopK2{
    set<T> s;
    int k;
public:
    void add(T a){
        if(k <=0 ) return;
        if(s.size() >= k && a < *(s.begin())){
            return;
        }
        if(s.insert(a) && s.size() > k) {
            s.erase(s.begin());
        }
    }

    vector<T> getK(){
        vector<T> res;
        for(int i = 0; i < s.size(); i++) {
            res.push_back(s[i]);
        }
        return res;
    }
};

/* Not tested.
 * Time complexity: O(n log k) in both cases assuming set is implemented as a bst or similar.
 * Space complexity: O(k)
 */
