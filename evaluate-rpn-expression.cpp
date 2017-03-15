/* LC 150
 *  Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Some examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include<iostream>
#include<stack>
#include<string>
#include<climits>
using namespace std;

bool isOperator(string s) {
  if(!s.compare("+") || !s.compare("-") || !s.compare("*") || !s.compare("/")) return true;
  return false;
}
int eval(int o1, int o2, string op) {
  if(!op.compare("+")) return o1+o2;
  if(!op.compare("-")) return o1-o2;
  if(!op.compare("*")) return o1*o2;
  if(!op.compare("/")) return o1/o2;
}
int evaluate(vector<string>& A) {
  stack<int> s;
  int n = A.size();
  for(int i = 0; i < n; i++) {
    if(isOperator(A[i]) {
      if(s.empty()) return INT_MIN;
      int op2 = s.top();
      s.pop();
      if(s.empty()) return INT_MIN;
      int op1 = s.top();
      s.pop();
      s.push(eval(op1,op2,A[i]));
    } else {
      s.push(stoi(A[i]));
    }
  }
  if(s.empty() || s.size() > 1) return INT_MIN;
  return s.top();
}
       
/* Tested.
 * Time complexity: O(n) where n is the number of tokens.
 * Space complexity: O(n).
 */

