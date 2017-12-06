/* LC 140
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.
 * Return all such possible sentences.
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 * A solution is ["cats and dog", "cat sand dog"].
 */
 
 vector<string> combine(string s, vector<string> tmp) {
        for(string &t: tmp) {
            t = s + " " + t;    
        }
        return tmp;
    }
    
    vector<string> helper(string s, unordered_set<string> &d, unordered_map<string,vector<string>> &m) {
        if(m.count(s)) return m[s];
        vector<string> res;
        //similar to prev prob but we dont return. For eg., if we find 'code' in the dict, we want to add it as one combination and see if it can be broken down further.
        if(d.count(s)) res.push_back(s);
        
        for(int sz = 1; sz < s.size(); sz++) {
            string sub = s.substr(0,sz);
            if(d.count(sub)) {
                //this iteration's result is sub + " " + {each element of the result of recursion}
                vector<string> tmp = combine(sub, helper(s.substr(sz),d,m));
                // once combined, these combinations go to the final result
                res.insert(res.end(),tmp.begin(),tmp.end());
            }
        }
        //memoize once for all here irrespective of whether the result was empty or not.
        m[s] = res;
        //only return once all recursions are done
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        unordered_map<string,vector<string>> m;
        return helper(s, dict, m);
    }
    
    /* Tested.
     * Time complexity: O(n^n) = exponential if not memoized. Polynomail if memoized - check leetcode discuss for highest voted.
     * Space complexity: O(n)
     */
