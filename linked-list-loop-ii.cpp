/* LC 142
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Note: Do not modify the linked list.
 * Follow up:
 * Can you solve it without using extra space?
 */
 
 #include<iostream>
 using namespace std;
 
 ListNode *detectCycle(ListNode *head) {
        ListNode* f = head;
        ListNode* s = head;
        
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
    
    /* Tested.
     * Time complexity:O(n) where n is the number of nodes.
     * Space complexity:O(1)
     */
