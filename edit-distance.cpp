/* LC 72
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 * You have the following 3 operations permitted on a word:
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 */
 #include<iostream>
 using namespace std;
 
 int minD(string w1, string w2) {
     int m = w1.length(), n = w2.length();
     vector<int> dp(m+1,0);       // using this row for all columns
     /*
     think of the edit distance regular dp matrix to be something like this
         X s u n d a y
       s 0 1 2 3 4 5 6
       a 1 0 1 2 3 4 5
       t 2 - - - - - - 
       u 3 - - - - - - 
       r 4 - - - - - -
       
       Now,dp[] represents each row at each iteration
       First iteration: it represents row [0,1,2,3,4,5,6]. This is the initialization done at (1)
       Second iteration done by the inner for loop, it becomes [0,0,1,2,3,4,5]
       and so on.
       
       to compute dp[i] we need only 3 other values(x,y,z):
       x y=old dp[i]
       z dp[i]
       
       pre stores x
       dp[i-1] gives z
       old dp[i] is stored in y
       */
     for(int i = 1; i <= m; i++) {
        dp[i] = i;        
     }      // row 0 initialization(1)
     
     for(int j = 1; j <= n; j++) {
        int pre = dp[0];    //store x
        dp[0] = j;    //column 0 initialization
        for(int i = 1; i <= m; i++) {
            int temp = dp[i];
            if(w1[i-1] == w2[j-1]) {
                dp[i] = pre;
            } else {
                dp[i] = 1+min(pre,min(dp[i],dp[i-1]));
            }
            pre = temp;
        }
     }
     return dp[m];
 }
 
 /* Tested.
  * Note: Traditional O(n*m) space method dp exists everywhere.
  * Time complexity: O(n*m)
  * Space complexity: O(m) or O(n) based on what you store
  */
