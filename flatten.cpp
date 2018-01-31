/* Given a doubly linked list with next,prev and up,down pointers, flatten the list.
 * Refer to eg. in main()
 */
 
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
    int val;
    struct Node *next;
    struct Node *prev;
    struct Node *up;
    struct Node *down;
}Node;

Node *newNode(int val) {
    Node * nn = (Node *)malloc(sizeof(Node));
    nn->val = val;
    nn->next = NULL;
    nn->prev = NULL;
    nn->up = NULL;
    nn->down = NULL;
    return nn;
}

void flatten(Node *head) {
    Node *cur = head;

    while(cur){
        Node *next = cur->next;
        Node *up = cur->up;
        Node *down = cur->down;
        Node *tophead = NULL;
        Node *toptail = NULL;
        Node *downhead = NULL;
        Node *downtail = NULL;
        if(up){
            cur->up = NULL;
            up->down = NULL;
            tophead = up;
            toptail = up;
            while(tophead->prev){
                tophead = tophead->prev;
            }
            while(toptail->next){
                toptail = toptail->next;
            }
        }

        if(down){
            cur->down = NULL;
            down->up = NULL;
            downhead = down;
            downtail = down;
            while(downhead->prev){
                downhead = downhead->prev;
            }
            while(downtail->next){
                downtail = downtail->next;
            }
        }
        
        if(up && down) {
            cur->next = tophead;
            tophead->prev = cur;
            toptail->next = downhead;
            downhead->prev = toptail;
            if(next)
             next->prev = downtail;
            downtail->next = next;
        } else if(up){
            cur->next = tophead;
            tophead->prev = cur;
            toptail->next = next;
            if(next)
              next->prev = toptail;
        } else if(down){
            cur->next = downhead;
            downhead->prev = cur;
            downtail->next = next;
            if(next)
               next->prev = downtail;
        }
        cur = cur->next;
    }
}

int main(){
    /*
     * 8 4-5
     * |   |
     * 1---2----3--10
     *     |    |
     *     6-7  9
     */
    Node *head = NULL;
    head = newNode(1);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(10);
    head->next->next->next->prev = head->next->next;

    head->next->up = newNode(5);
    head->next->up->down = head->next;
    head->next->up->prev = newNode(4);
    head->next->up->prev->next = head->next->up;
    head->next->down = newNode(6);
    head->next->down->up = head->next;
    head->next->down->next = newNode(7);
    head->next->down->next->prev = head->next->down;

    head->up = newNode(8);
    head->up->down = head;

    head->next->next->down = newNode(9);
    head->next->next->down->up = head->next->next;

    flatten(head);
    Node *cur = head;
    while(cur){
        cout << cur->val << ",";
        cur = cur->next;
    }
    return 0;
}

/* Not tested thoroughly.
 * Time complexity: O(n) where n is the total number of nodes.
 * Space complexity: O(1)
 */
