/* LC 23
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */
#include<iostream>
#include<vector>
using namespace std;

// Approach 1: Use existing merge2lists code
void append(ListNode*& head, ListNode*& tail, ListNode*& l) {
        head? tail->next=l : head=l;
        tail = l;
    }
    void append_and_advance(ListNode*& head, ListNode*& tail, ListNode*& l) {
        append(head,tail,l);
        l = l->next;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, *tail = NULL;
        
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return NULL;
        while(lists.size()>1) {
            lists.push_back(mergeTwoLists(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }

// Approach 2: Optimize above
ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        int k = lists.size();
        if(!k) return head;
        for(int i = 0; i < k; i++) {
            head = mergeTwoLists(head,lists[i]);
        }
  return head;
}

// Approach 3: Most optimized method of using merg2lists - divide and conquer
ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(!k) return NULL;
        if(k==1) return lists[0];
        if(k==2) return mergeTwoLists(lists[0],lists[1]);
        vector<ListNode*> l1(lists.begin(),lists.begin()+lists.size()/2);
        vector<ListNode*> l2(lists.begin()+lists.size()/2,lists.end());
        return mergeTwoLists(mergeKLists(l1),mergeKLists(l2));
    }

/* Tested.
 * Time complexity:
 * merge2lists takes O(n) where n is the length of shorter list.
 * Approach 1: O(nklogk). 1st iteration: k lists of n each, 2nd iteration: k/2 lists of 2n each...nk+2n(k/2)+4n(k/4)... = kn(logk)
 * Approach 2: O(kn). // To be verified since this approach is taking longer on LC but seems to have lesser time complexity.
 * Approach 3: O(nlogk) where n is the total number of elements of all lists combined. View it like a BT. Suppose k is 8: root is 8, next level is 4,4. Next is 2,2,2,2. Next is 1,1,1,1,1,1,1,1. Number of elements in each level is n. And there are 3  (log8) levels. So, total is 3n = nlog8 = nlogk.
 * Space complexity: Approach 1 and 2: O(1). Approach 3: O(log k) since we perform merge log k times.
 */
