/* LC 139
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * Return true because "leetcode" can be segmented as "leet code".
 */
 
 bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        
        //implement dict as set for easier random access
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        //i represents 'ending here'
        for(int i = 1; i <= n; i++) {
        //j represents start of the substring to evaluate
            for(int j = 0; j < i; j++) {
            //if substring until j-1 has been a valid word, find the substr from j for appropriate size. If j=0, substr starts at 0 and has i chars sz to evaluate, as j increases, sz to evaluate decreases since we have to evaluate only until i, hence i-j. 
                if(dp[j] && dict.find(s.substr(j,i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    /* Tested.
     * Time complexity: O(n^2)
     * Space complexity: O(n)
     */
