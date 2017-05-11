/* LC 322
 *  You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 * Note:
 * You may assume that you have an infinite number of each kind of coin. 
 */
 #include<iostream>
 #include<vector>
 #include<climits>
 using namespace std;
 
 int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i = 0; i <= amount; i++) {
            dp[i] = INT_MAX;
        }
        
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++) {
                if(coins[j] <= i && dp[i-coins[j]] != INT_MAX && dp[i]>dp[i-coins[j]] +1) {  //pay heed to overflow here
                    dp[i] = dp[i-coins[j]] + 1;
                }
            }
        }
        return (dp[amount] == INT_MAX)? -1: dp[amount];
    }
    
    /* Tested.
     * Time complexity: O(n*amount) where n is the number of coin denominations.
     * Space complexity: O(amount)
     */
