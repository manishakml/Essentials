/* LC 5
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example:
 * Input: "cbbd"
 * Output: "bb"
 */
#include<iostream>
#include<string>
using namespace std;

//Approach 1 - 2 pointers
string longestPalindrome(string s) {
        int n = s.length(), maxL = 1, start = 0;
        if(n < 2) return s;
        for(int i = 0; i < n && n-i > maxL/2;) {
            int l = i, r = i;
            while(r < n-1 && s[r+1] == s[r]) {
                r++;
            }
            i = r+1;
            while(l > 0 && r < n-1 && s[l-1] == s[r+1]) {
                r++;
                l--;
            }
            if(r-l+1 > maxL) {
                maxL = r-l+1;
                start = l;
            }
        }
        return s.substr(start, maxL);
    }

//Approach 2 - dp
string longestPalindrome(string s) {
        int n = s.length(), maxL = 1, start = 0;
        if(n < 2) return s;
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                maxL = 2;
                start = i;
            }
        }
        
        for(int L = 3; L <= n; L++) {
            for(int i = 0; i < n-L+1; i++) {
                int j = i+L-1;
                if(s[i]==s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if(maxL < L){
                        maxL = L;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxL);
    }

/* Tested.
 * Note: LPST can be solved without extra space or dp using 2ptr method.
 * Time complexity: O(n^2) worst case, O(n) best case using approach 1. Eg.: "bbbbb" for best case; O(n^2) for dp.
 * Space complexity: O(n^2) for dp, O(1) for 2ptr.
 */
  
