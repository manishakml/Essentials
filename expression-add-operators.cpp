/* LC 282
 * Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
 * Examples: 
 * "123", 6 -> ["1+2+3", "1*2*3"] 
 * "232", 8 -> ["2*3+2", "2+3*2"]
 * "105", 5 -> ["1*0+5","10-5"]
 * "00", 0 -> ["0+0", "0-0", "0*0"]
 * "3456237490", 9191 -> []
 */
 
 void helper(vector<string> &R, string result, long long prev_op, long long total, int target, string num){
        if(num.length() == 0) {
            if(target == total) {
                R.push_back(result);
            }
            return;
        }
        
        for(int i = 1; i <= num.length(); i++) {
            string sub = num.substr(0,i);
            if(sub.length() > 1 && sub[0] == '0') {
                return;
            }
            string s = num.substr(i);
            if(result.length() > 0) {
                helper(R,result+"+"+sub,stoll(sub),total+stoll(sub),target,s);
                helper(R,result+'-'+sub,-stoll(sub),total-stoll(sub),target,s);
                helper(R,result+'*'+sub,prev_op*stoll(sub),(total-prev_op)+(prev_op*stoll(sub)),target,s);
            } else {
                helper(R,sub,stoll(sub),stoll(sub),target,s);
            }
        }
        
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> R;
        helper(R,"",0,0,target,num);
        return R;
    }
    
    /* Tested.
     * Time complexity: O(n^n) - exponential. Consider a recursion tree. It starts with n n chars and goes until 0 chars. So, ht is n. At each level, it forks into 3 (+-*). Each of these 3 are subdivided into (n-1) branches. So, 3n + (3^2)(n-1)...
     * Space complexity: O(n) = height of the tree.
     */
