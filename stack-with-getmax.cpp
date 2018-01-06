/* Implement a stack with push, pop, getmax */

stack<int> s;
stack<int> aux;

MinStack::MinStack() {
    while(!s.empty()) s.pop();
    while(!aux.empty()) aux.pop();
}

void MinStack::push(int x) {
    s.push(x);
    if(aux.empty() || x <= getMin()) aux.push(x);
}

void MinStack::pop() {
    if (s.empty()) return;
    if(!aux.empty() && (s.top() == getMin())) aux.pop();
    s.pop();
}

int MinStack::top() {
    return s.empty()? -1 : s.top();
}

int MinStack::getMin() {
    return aux.empty()? -1 : aux.top();
}


/* Tested.
 * Time complexity: O(1), O(1), O(1)
 * Space complexity: O(n)
 */
