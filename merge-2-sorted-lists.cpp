/* LC 21
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

#include<iostream>
using namespace std;

void append(List*&h, List*&t, List*& l) {
  h?t->next = l:head = l;
  tail = l;
}
void append_and_advance(List*& h, List*& t, List*& l) {
  append(h,t,l);
  l=l->next;
}
List* merge(List* l1, List* l2) {
  List *head = NULL, *tail = NULL;
  while(l1 && l2) {
    append_and_advance(head,tail,l1->val<l2->val?l1:l2);
  }
  if(l1) {
    append(head,tail,l1);
  }
  if(l2) {
    append(head,tail,l2);
  }
  return head;
}

/* Tested.
 * Time complexity: O(n) where n is the size of shorter list.
 * Space complexity: O(1).
 */
  
