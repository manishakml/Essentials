/* LC 516
 * Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
 * Example 1:
 * Input:
 * "bbbab"
 * Output:
 * 4
 * One possible longest palindromic subsequence is "bbbb".
 * Example 2:
 * Input:
 * "cbbd"
 * Output:
 * 2
 * One possible longest palindromic subsequence is "bb".
 */
 #include<iostream>
 #include<string>
 #include<cstring>
 using namespace std;
 
 int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for(int L = 2; L <= n; L++) {
            for(int i = 0; i < n-L+1; i++) {
                int j = i+L-1;
                if(L==2 && s[i] == s[j]) {
                    dp[i][j] = 2;
                } else if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
    
    /* Tested.
     * Time complexity: O(n^2) where n is the length of string.
     * Space complexity: O(n^2)
     */
