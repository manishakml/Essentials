/* LC 67
 *  Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100". 
 */
 
 #include<iostream>
 #include<string>
 using namespace std;
 
 string add(string a, string b) {
  string res = "";
  int c = 0;
  for(int i = a.length()-1,j = b.length()-1; i>=0,j>=0; i--,j--) {
    int m = i>=0 && a[i]=='1';
    int n = j>=0 && b[j]=='1';
    int sum = m+n+c;
    res = to_string(sum&1) + res;
    c = sum>>1;
  }
  
  return c?'1'+res:res;
 }
