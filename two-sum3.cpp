/* LC 170
 * Design and implement a TwoSum class. It should support the following operations: add and find.
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the value.
 * For example,
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
*/

#include <iostream>
#include <unordered_set>
using namespace std;

class TwoSum {
  unordered_multiset<int> m;
public:
  TwoSum() {
    m.clear();
  }
  
  void add(int x) {
    m.insert(x);
  }
  
  bool find(int sum) {
    for(int a : m) {
      int count = (value-a == a)? 1 : 0;
      if(m.count(value-a) > count) {
        return true;
      }
    }
    return false;
  }
};

//alternate implementation
class TwoSum {
    unordered_map<int,int> m;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        m.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        if(m.find(number) != m.end()) {
            m[number]++;
        } else {
            m[number] = 1;
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(pair<int,int> a : m) {
            if(value-a.first == a.first && m[a.first] > 1) {
                return true;
            } else if (value-a.first != a.first && m.find(value-a.first) != m.end()){
                return true;
            }
        }
        return false;
    }
};

/* Tested.
 * Time complexity: O(n) where n is the number of elements in the list
 * Space complexity: O(n).
 */
