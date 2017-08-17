/* Given an input string, text string and replacement string, replace all occurences of text string in input string to replacement string.
 * Example: Input: "abcddddddab", text-string: ab, replacement string: cab yields "cabcddddddcab". The replacement string can be bigger/smaller than the text string.
 */
 
 #include<iostream>
 #include<string>
 using namespace std;
 
 string str_replace(string s, string a, string b) { // a is the text string, b is the replacement string
  if(s.length() == 0 || a.length() == 0 || b.length() == 0 || a.equals(b)) return s;  //clarify what needs to be done - these are edge cases
  int idx = s.find(a);
  if(idx == npos) return s;
  return s.substr(0,idx) + b + str_replace(s.substr(idx+a.length()),a,b);
 }
 
 /* Not tested.
  * Time complexity:O(n*m) where n is the input string length and m is the length of a.
  * Space complexity: O(n) for the call stack
  */
