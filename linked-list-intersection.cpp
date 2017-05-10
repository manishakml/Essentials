/* LC 160
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 */
  
 #include<iostream>
 #include<cmath>
 using namespace std;
 
 int count(ListNode* h) {
        int c = 0;
        while(h) {
            c++;h = h->next;
        }
        return c;
    }
    
    void advance(ListNode* &l, int d) {
        while(d--) {
            l = l->next;
        }
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = count(headA);
        int c2 = count(headB);
        
        advance(c1>c2?headA:headB,abs(c1-c2));
        
        while(headA && headB && headA!=headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
    
    /* Tested.
     * Time complexity: O(n) where n is the number of nodes.
     * Space complexity:O(1)
     */
  
