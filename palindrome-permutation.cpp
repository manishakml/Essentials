/**
 * Leetcode 266
 * Given a string, determine if a permutation of the string could form a palindrome.
 * For example,
 * "code" -> False, "aab" -> True, "carerac" -> True.
 */
 
 #include<iostream>
 #include<map>
 using namespace std;
 
 bool canFormPalindrome(string s) {
    unordered_map<char, int> hash;
    int odd_count = 0;
    
    for(char c: s) {
       hash[c]++;
    }
    
    for(pair<char,int> p : hash) {
       if(p.second & 1 && ++odd_count > 1) {
          return false;
       }
    }
    return odd_count <= 1;
 }
 
 /**
  * Time complexity:  O(n) where n is the number of characters in the string.
  * Space complexity: O(1) since it is a hashmap for all characters.
  * Not tested but verified from EPI.
  */
