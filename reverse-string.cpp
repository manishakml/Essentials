/**
 * Leetcode 344
 * Write a function that takes a string as input and returns the string reversed.
 * Example:
 * Given s = "hello", return "olleh".
 */
 
 #include <iostream>
 using namespace std;
 
 string reverse(string s) {
    if(s.length() == 0) {
       return s;
    }
    int i = 0, j = s.length()-1;
    for(; i < j; i++,j--) {
       swap(s[i],s[j]);
    }
    return s;
  }
  
  /**
   * Time complexity:  O(n) where n is the number of characters in the string.
   * Space complexity: O(1).
   * Of course, a smart answer would be to use std::reverse().
   */
