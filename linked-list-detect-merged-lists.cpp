/* Detect if 2 given linked lists are merged at some point.
 * Note: Lists may or may not have cycles in them
 */

#include<iostream>
using namespace std;

bool cycle(List *head) {
        List* f = head, *s = head;
        
        while(s && s->next && s->next->next){
            f = f->next;
            s = s->next->next;
            if(f == s) {
                return true;
            }
        }
        return false;
}

bool detect_merge(List* h1, List* h2) {
  List* a = cycle(h1);
  List* b = cycle(h2);
  if(!a && !b) {
    // Sufficient to check if the last nodes are the same if there is no cycle.
    while(h1->next) {
      h1 = h1->next;
    }
    while(h2->next) {
      h2 = h2->next;
    }
    if(h1 == h2) {
      return true;
    }
  // Both have cycles: They could be standalone lsits with cycles OR they could be merged at some point and share the cycle from there. So, head_of_cycle_1 should be able to travel the loop to find head_of_cycle_2.
  } else if(a && b) {
    if(a == b) {
      return true;
    }
    List *tmp = a;
    do{
      tmp = tmp->next;
      if(tmp == b) {
        return true;
      }
    }while(tmp != a);
  }
  // Case: Either list has cycle or some list is NULL etc.
  return false;
}

/* Not tested.
 * Time complexity:O(n+m) where n and m are the 2 list lengths.
 * Space complexity: O(1)
 */
