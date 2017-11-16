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

//Using pos, rather than creating multiple strings

void helper(vector<string> &R, string result, long long prev_op, long long total, int target, string num,int pos){
        if(pos == num.length()) {
            if(target == total) {
                R.push_back(result);
            }
            return;
        }
        
        for(int i = pos; i < num.length(); i++) {
            string sub = num.substr(pos,i-pos+1);
            if(i > pos && num[pos] == '0') {
                return;
            }
            long long val = stoll(sub);
            if(pos > 0) {
                helper(R,result+"+"+sub,val,total+val,target,num,i+1);
                helper(R,result+'-'+sub,-val,total-val,target,num,i+1);
                helper(R,result+'*'+sub,prev_op*val,(total-prev_op)+(prev_op*val),target,num,i+1);
            } else {
                helper(R,sub,val,val,target,num,i+1);
            }
        }
        
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> R;
        helper(R,"",0,0,target,num,0);
        return R;
    }
    //To add division as well: watch out for /0
    #include<iostream>
#include<vector>
#include<string>
using namespace std;

void helper(vector<string> &R, string result, long long prev_op, long long total, int target, string num,int pos){
        if(pos == num.length()) {
            if(target == total) {
                R.push_back(result);
            }
            return;
        }

        for(int i = pos; i < num.length(); i++) {
            string sub = num.substr(pos,i-pos+1);
            if(i > pos && num[pos] == '0') {
                return;
            }
            long long val = stoll(sub);
            if(pos > 0) {
                helper(R,result+"+"+sub,val,total+val,target,num,i+1);
                helper(R,result+'-'+sub,-val,total-val,target,num,i+1);
                helper(R,result+'*'+sub,prev_op*val,(total-prev_op)+(prev_op*val),target,num,i+1);
                if(val){
                        helper(R,result+'/'+sub,prev_op/val,(total-prev_op)+(prev_op/val),target,num,i+1);
                }
            } else {
                helper(R,sub,val,val,target,num,i+1);
            }
        }

    }

    vector<string> addOperators(string num, int target) {
        vector<string> R;
        helper(R,"",0,0,target,num,0);
        return R;
    }

    /* Tested. Division not tested toroughly.
     * Time complexity: O(n^n) - exponential. Consider a recursion tree. It starts with n n chars and goes until 0 chars. So, ht is n. At each level, it forks into 3 (+-*). Each of these 3 are subdivided into (n-1) branches. So, 3n + (3^2)(n-1)...
     * Space complexity: O(n) = height of the tree.
     */
