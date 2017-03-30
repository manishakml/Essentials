/* LC 168
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
  */

#include<iostream>
#include<string>
using namespace std;

string excel(int n) {
  string res="";
  while(n) {
    res += 'A' + (n-1)%26;
    n = (n-1)/26;
  }
  reverse(res.begin(),res.end());
  return res;
}

/* Tested.
 * Note: (n-1) has been used to handle cases such as 'Z' which return 0 on modulus
 * Time complexity: O(log n) with base 26.
 * Space complexity: O(1)
 */
  
