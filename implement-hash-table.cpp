/* Implement a hash table with put and get methods */

#include<iostream>
#include<vector>
#include<functional>
#include<string>
using namespace std;

template<class K, class V>
struct Node {
    K key;
    V val;
    Node(K k, V v) : key(k), val(v) {}
};

template<class T>
struct myHash {
};

template<>
struct myHash<string> {
    size_t hashFunc(const string &s){
        return std::hash<string>()(s);
    }
};
template<>
struct myHash<int> {
    size_t hashFunc(const int &m){
        return std::hash<int>()(m);
    }
};

template<class K, class V, class HashGen = myHash<K> >
class HashTable {

    vector<list<Node<K,V> > > table;
    vector<std::mutex> locks;
   public:
    HashTable(int size) {
        table.resize(size);
        locks.resize(size);
    }
    ~HashTable() {}
    size_t mhash(K key) {
        return HashGen::hashFunc(key) % table.size();
    }

    void put(K key, V val) {
        size_t idx = mhash(key);
        std::unique_lock<std::mutex> mlock(locks[idx]);
        for(list::iterator i = table[idx].begin(); i != table[idx].end(); i++){
            if(i->key == key) {
                i->val = val;
                return;
            }
        }
        Node<K,V> nn(key,val);
        table[idx].push_back(nn);
        mlock.unlock();
    }

    bool get(K key, V &v) {
        size_t idx = mhash(key);
        std::unique_lock<std::mutex> mlock(locks[idx]);
        for(int i = table[idx].begin(); i != table[idx].end(); i++){
            if(i->key == key) {
                v =  i->val;
                return true;
            }
        }
        return false;
        mlock.unlock();
    }
};

/* Not tested.
 * Time complexity: O(n) where collision factor is n (n keys collide)
 * Space complexity: O(n*size) - for a hash table of size 'size' and n collision factor.
 */
