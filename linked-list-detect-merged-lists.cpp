/* Detect if 2 given linked lists are merged at some point.
 * Note: Lists may or may not have cycles in them
 */

#include<iostream>
using namespace std;

List *detectCycle(List *head) {
        List* f = head;
        List* s = head;
        
        while(s && s->next && s->next->next) {
            f = f->next;
            s = s->next->next;
            if(f == s) {
                int c = 0;
                do{
                    s = s->next;
                    c++;
                }while(f!=s);
                f = head; s = head;
                while(c) {
                    s = s->next;
                    c--;
                }
                while(f!=s) {
                    f = f->next;
                    s = s->next;
                }
                return f;
            }
        }
        return NULL;
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
      //if we have to return start of the merge: Use linked-list-intersection.cpp logic here.
      return true;
    }
  // Both have cycles: They could be standalone lists with cycles OR they could be merged at some point and share the cycle from there. So, head_of_cycle_1 should be able to travel the loop to find head_of_cycle_2.
  } else if(a && b) {
    if(a == b) {
      //If we have to return point of merge, return a (or b) here.
      return true;
    }
    List *tmp = a;
    do{
      tmp = tmp->next;
      if(tmp == b) {
        // If we have to return point of merge, return tmp here.
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
