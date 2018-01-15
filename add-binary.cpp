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

//approach 2
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size()-1, j = b.size()-1, carry = 0;
        
        while(i >=0 || j >=0 || carry == 1) {
            int A = i >= 0? a[i]-'0' : 0;
            int B = j >= 0? b[j]-'0' : 0;
            int sum = A + B + carry;
            res += (sum & 1) + '0';
            carry = sum >> 1;
            i--;j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
