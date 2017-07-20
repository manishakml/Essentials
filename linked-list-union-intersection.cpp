/* Given 2 sorted linked lists, find the union and intersection of them.*/

//Union is same as merge-2-linked-lists. Union will include duplicates
//To avoid duplicates, use the following to the result list
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur->next) {
            if(cur->val == cur->next->val){
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
 }

//Intersection. If l1 = {1,2,3,4,5}, l2 = {2,2,4,6}, intersection has {2,4} and not {2,2,4}. It is not clear if this is the intended result.
void a_n_a(List *&h, List *&t, List *&l1, List *&l2){
    h?t->next=l1:h=l1;
    t = l1;
    l1 = l1->next; l2 = l2->next;
}

List *intersection(List *l1, List *l2) {
    List *h = NULL, *t = NULL;

    while(l1 && l2) {
        if(l1 && l2 && l1->val < l2->val) l1 = l1->next;
        if(l1 && l2 && l2->val < l1->val) l2 = l2->next;
        if(l1 && l2 && l1->val == l2->val) a_n_a(h,t,l1,l2);
    }
    t->next = NULL;
    return h;
}

/* Intersection not tested thoroughly.
 * Time complexity: O(n+m) wher n and m are list lengths.
 * Space complexity: O(1).
 */

