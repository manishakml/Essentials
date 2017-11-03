/* LC 17
 * Given a digit string, return all possible letter combinations that the number could represent.
 */
 class Solution {
    vector<string> m = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void helper(string digits, vector<string> &res, string ans, int pos,int n) {
        if(pos == n){
            res.push_back(ans);
            return;
        }
        for(const char &a: m[digits[pos] - '0']) {
            ans[pos] = a;
            helper(digits,res,ans,pos+1,n);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        if(!n) return res;
        string ans(n,0);        
        helper(digits,res,ans,0,n);
        return res;
    }
};

 /* Variation: Return all possible valid words only.
  * Expanded solution could generate every string as above and check validity assuming dictionary is implemented as a set
  */
 
 /* Tested.
  * Time complexity: O(4^n) Exponential (4 chars per digit max, n-char string. Possibility: 4*4*4*4...n times
  * Space complexity: O(n) for the recursion stack.
  */
  ----------------------------------------------------------------------------------------------------------------------------------
 /* Optimization:
  * The above algortihm runs very slow. We can implement the dictionary as a trie. That way, we can progress to the next character of the string only if the trie has it as a child (and hence, valid).
  * This reduces the number of paths to traverse and can reduce the time taken.
  */
   
   
