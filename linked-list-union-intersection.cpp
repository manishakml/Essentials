/* Given 2 sorted linked lists, find the union and intersection of them.*/

//You cannot use merge logic and then apply dedup on it. Reason: If A has duplicate nodes in itself, union should have the duplicate nodes.
//Combining dedup in merge logic, union can be written as follows
List* union(List *a, List *b){
        List *h = NULL, *t = NULL;
        while(a && b){
                //store a and b vals
                int A = a->val;
                int B = b->val;
                //if they are equal, we have to merge only one, but move both. From our logic below, if they are equal b is merged and moved. So, a has t be moved explicitly.
                if(A == B) a = a->next;
                a_n_a(h,t,A<B?a:b);
        }
        if(a){
                a_n(h,t,a);
        }
        if(b){
                a_n(h,t,b);
        }
        return h;
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
            
            /*alternative - easier code
            if(l1->val < l2->val) {
                    l1 = l1->next;
            }else if(l2->val < l1-val){
                    l2 = l2->next;
            } else {
                a_n_a(h,t,l1,l2);
            }*/
    }
    t->next = NULL;
    return h;
}

/* Intersection not tested thoroughly.
 * Time complexity: O(n+m) wher n and m are list lengths.
 * Space complexity: O(1).
 */

