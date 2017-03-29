/* LC 125
 *  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome. 
 */

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool isPalindrome(string s) {
  int l = 0, n = s.length()-1, r = n-1;
  
  while(l < r) {
    while(l<r && !isalnum(s[l])) l++;
    while(l<r && !isalnum(s[r])) r--;
    
    if(l<r && tolower(s[l]) != tolower(s[r])) return false;
    l++; r--;
  }
  return true;
}

/* Tested.
 * Time complexity: O(n) where n is the length of the string.
 * Space complexity: O(1).
 */
