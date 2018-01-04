/* Given an input string, text string and replacement string, replace all occurences of text string in input string to replacement string.
 * Example: Input: "abcddddddab", text-string: ab, replacement string: cab yields "cabcddddddcab". The replacement string can be bigger/smaller than the text string.
 */
 
 #include<iostream>
 #include<string>
 using namespace std;
 
 string str_replace(string s, string a, string b) { // a is the text string, b is the replacement string
  if(s.length() == 0 || a.length() == 0 || a==b) return s;  //clarify what needs to be done - these are edge cases
  int idx = s.find(a);
  if(idx == npos) return s;
  return s.substr(0,idx) + b + str_replace(s.substr(idx+a.length()),a,b);
 }

//approach 2 - iterative. Recursive creates a lot of unnecessary strings
//this approach does not do in place (neither does the previous)

#include<iostream>
#include<string>
using namespace std;

string replace(string s, string a, string b){
 if(s.length() == 0 || a.length() == 0 || a==b) return s;
 string res = "";

 for(int i = 0; i < s.length();){
  int idx = s.find(a,i);   //starts search from idx i
  if(idx == string::npos) {
    res += s.substr(i);   // copy the remaining string
    return res;
  };
  res += s.substr(i, idx-i) + b; //copy the part until a from where we left off and append b
  i = idx + a.length(); //move i to after a
 }
 return res;
}

int main(){
    cout << replace("foobarbarfodfoodgate", "foo", "egg");
    return 1;
}
 
 /* Not tested.
  * Time complexity:O(n*m) where n is the input string length and m is the length of a. C++ string find is implemented as O(n*m). Otherwise it is a linear algorithm above.
  * Space complexity: O(n) for the call stack
  */
