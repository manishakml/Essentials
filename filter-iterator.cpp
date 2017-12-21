/* Implement a specialized iterator called filterIterator which iterates over elements that satisfy a condition given to us, called predicate. */
//This is just a prototype. Assumptions: C++ has an iterator like Java, with next(), hasNext() and remove().

Iterator it;   //assuming c++ has somehting similar
bool apply();   //predicate/condition given to us

template<typename T>
class filterIterator extends Iterator {
    T *res = nullptr;
    public:
        filterIterator(){
            while(it.hasNext()){
                T tmp = it.next();
                if(tmp.apply()) {
                    *res = tmp;
                    break;
                }// apply the predicate/condition
            }
        }

        bool hasNext(){
            return (res != nullptr);
        }

        T next(){
            T result = *res;
            res = nullptr;

            while(it.hasNext()){
                T tmp = it.next();
                if(tmp.apply()){
                    *res = tmp;
                    break;
                }
            }
            return result;
        }
        //remove() cannot be safely implemented because next() returns an elemtn but progresses towards the next eligible element. So, calling remove() using underlying it.remove() will cause some other further element to be removed and not the intended one.
};

/* Not tested.
 * Time complexity: hasNext() is O(1), next() is O(n) ssuming the container has n elements.
 * Space complexity: O(1).
 */
