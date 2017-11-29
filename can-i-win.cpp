/* LC 464
 * In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.
 * What if we change the game so that players cannot re-use integers?
 * For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
 * Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.
 * You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
 * Example
 * Input:
 * maxChoosableInteger = 10
 * desiredTotal = 11
 * Output:
 * false
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
 * Same with other integers chosen by the first player, the second player will always win.
 */
 
 class Solution {
public:
    
    bool helper(int maxChoosableInteger, int desiredTotal, int state, unordered_map<int, bool> &m) {
        if(m.find(state) != m.end()){
            return m[state];        //It is a previously solved subproblem.
        }
        
        for(int i = 0; i < maxChoosableInteger; i++){
            if(state & (1 << i)) {
                continue;       // This i has already been used.
            }
            if(desiredTotal <= (i+1) || !helper(maxChoosableInteger, desiredTotal - (i+1), state|(1<<i), m)) { /*i+1 since i is iterating over 0-based indices but maxChoosable integer is from 1. We return true only if either of the conditions is satisfied, i.e, 1) opponent cannot win in the next move or 2) I can use this i to win directly in one shot (!helper(...) and there is no remaining total after I play (total <= (i+1)).*/
                m[state] = true;
                return true;
            }   
        }
        m[state] = false;
        return false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int maxAchievable = maxChoosableInteger * (1+maxChoosableInteger) / 2;  // Given n, we can get a max of 1+2...n = n*(n+1)/2
        if(maxAchievable < desiredTotal) {
            return false;
        }
        if(desiredTotal <= 0) {
            return true;
        }
        
        int state = 0;  /*We have to keep track of whether a number has been used or not. We could use a bool array for maxChoosableInteger. Since maxChoosableInteger is <=20, we could ust use a bit to indicate used or not. So, 20 bits. 1 integer is more than enough.*/
        unordered_map<int,bool> m;  // For each state, we indicate if we have seen it before and if seen, what was the outcome.
        
        return helper(maxChoosableInteger, desiredTotal, state, m);
    }
};
    
/* Tested.
 * Time complexity: O(2^n) since we are memoizin using the map. O(n^n) otherwise. n is maxChoosableInteger. We compute each subprob at most once. There are 2^n subprob -how? There are n choosable integers. Each integer has 2 states - used/unused. So, considering all combinations, 2*2*..n_times = 2^n
 * Space complexity: O(n)
 */
