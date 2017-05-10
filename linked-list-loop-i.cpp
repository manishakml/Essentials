/* LC 141
 * Given a linked list, determine if it has a cycle in it.
 * Follow up:
 * Can you solve it without using extra space?
 */
 
 #include<iostream>
 using namespace std;
 
 bool hasCycle(ListNode *head) {
        ListNode* f = head, *s = head;
        
        while(s && s->next && s->next->next){
            f = f->next;
            s = s->next->next;
            if(f == s) {
                return true;
            }
        }
        return false;
    }
    
    /* Tested.
     * Time complexity: O(n) where n is the number of nodes.
     * Space complexity:O(1)
     */
