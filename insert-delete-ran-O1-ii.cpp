/* LC 381
 * Design a data structure that supports all following operations in average O(1) time.
 * Note: Duplicate elements are allowed.
 * insert(val): Inserts an item val to the collection.
 * remove(val): Removes an item val from the collection if present.
 * getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
 * Example:
// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();
// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);
// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);
// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);
// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();
// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);
// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
 */
 
 class RandomizedCollection {
public:
    unordered_map<int,vector<int>> m;
    vector<pair<int,int>> A;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].push_back(A.size());
        A.push_back(make_pair(val,m[val].size()-1));
        if(m[val].size() > 1) return false;
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        int idx = m[val].back();
        int last = A.size()-1;
        A[idx] = A[last];
        m[A[last].first][A[last].second] = idx;
        A.pop_back();
        m[val].pop_back();
        if(m[val].size() == 0) m.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {     
        int r = rand()%A.size();
        return A[r].first;      
    }
};

//approach 2
vector<int> A;
unordered_map<int,unordered_set<int>> m;

bool insert(int a){
 A.push_back(a);
 m[a].insert(A.size()-1);
 if(m[].size() > 1) return false;
 return true;
}

bool remove(int a){
 if(!m.count(a)) return false;
 a_idx = m[a]->begin();
 m[A.size()-1].erase(A.size()-1));
 m[A.size()-1].insert(a_idx);
 A[a_idx] = A[A.size()-1];
 A.pop_back();
 m[a].erase(m[a]->begin());
 return true;
}
 
int getRandom(){
 int r = rand()%A.size();
 //remove(A[r]);
 return A[r];
}
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
 
 /* Tested.
  * Note: To use templates, refer hashtable problem.
  * Time complexity: O(1)
  * Space complexity: O(n) where n is the number of elements.
  */
