/* Implement a rank-based cache eviction.
 * Assume you have a method to get rank of an object.
 * Assume you have a method to get the element from a store (initialized in ctor), but it is slow.
 */
 
 //assumes rank 1 is highest priority
//assumes ranks don't change dynamically
//assumes that an incoming element is inserted into the map irrespective of whether it forms the lowest rank

template<class K, class V>
class RetainBestCache{
        vector<pair<K,V>> store_;       //to store the incoming collection
        int capacity_;                  //max capacity of the cache after which eviction begins
        unordered_map<K,V> cache_;      //cache of k,v pairs
        unordered_map<long,unordered_set<K>> rank_;     //stores elements' keys corresponding to each rank
        set<long> order_;               //ordered set of ranks. First element is the highest rank and last is the lowest

public:
        RetainBestCache(vector<pair<K,V>> &A, int size){
                store_ = A;
                capacity_ = size;
        }

        V get(K key){
                V res;
                if(!cache_.count(key)){         //if it is a cache miss
                        res = store_.get(key);
                        put(key,res);           //get from store and cache it
                } else {
                        res = cache_[key];
                }
                return res;
        }

        void put(K key, V val){
                cache_[key] = val;              //insert into cache
                long rank = val.getRank();      //get element's rank and put it in the rank set. Add the elem's key to the list of elements with its rank.
                order_.insert(rank);
                rank_[rank].insert(key);        
                if(cache_.size() > capacity){   //eviction
                        long lowest = order_->rbegin(); //get lowest rank
                        K k = rank_[lowest]->begin();   //get one of the lowest rank's keys
                        if(rank_[lowest].size() == 1){  //if that rank corresponds only to one element, remove the map entry for it in the rank map and remove the set entry for the rank
                                rank_.erase(lowest);
                                order_.erase(order->rbegin());
                        } else {                //remove only this instance from the rank map
                                rank_[lowest].erase(rank_[lowest]->begin());
                        }
                        cache_.erase(k);        //evict the k,v pair from the cache to make room
                 
                }
        }
};

/* If it has to be made thread safe, we use unique_lock on every cache, rank, order operation. But we have to avoid it on a store operation since it has been specified to be slow. */

/* Not tested.
 * Time: O(1) get if in cache, depends on the datastore implementation otherwise. O(log n) put (if it has to be evicted from order set).
 * Space: O(n)
 */
