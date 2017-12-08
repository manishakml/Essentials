/* LC 17
 * Given a digit string, return all possible legal letter combinations(valid words) that the number could represent.
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
   
   #include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

vector<string> m = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
};

void insert(TrieNode *root, string s){ 
   TrieNode *cur = root;
   for(const char &c: s){ 
      if(cur->children.find(c) == cur->children.end()){
        TrieNode *nn = new TrieNode();
        nn->isEnd = false;
        cur->children[c] = nn; 
      }   
      cur = cur->children[c];
   }   
   cur->isEnd = true;
}


void helper(string digits, vector<string> &res, string ans, int pos,int n, TrieNode *root) {
        // cout << "ans: " << ans << " pos: " << pos << " root: " << root << endl << flush;
        if(pos == n){ 
            res.push_back(ans);
            return;
        }   
        for(const char &a: m[digits[pos] - '0']) {
            if(root->children.find(a) == root->children.end()){
                continue;
            }   
            ans[pos] = a;
            helper(digits,res,ans,pos+1,n,root->children[a]);
        }   
}
vector<string> letterCombinations(string digits, TrieNode *root) {
        vector<string> res;
        int n = digits.size();
        if(!n) return res;
        string ans(n,0);
        helper(digits,res,ans,0,n,root);
        return res;
}
int main(){
        TrieNode *root = new TrieNode();
        root->isEnd = false;
        insert(root,"bat");
        insert(root,"sad");
        insert(root,"bar");
        insert(root,"zoo");
        insert(root,"foo");
        vector<string> res = letterCombinations("234",root);
        for(string s: res){
            cout << s;
        }   
        return 1;
}

/* Note tested thoroughly.
 * Time and Space complexity: Same as previous, but it has been optimized due to the trie.
 */
   
   
