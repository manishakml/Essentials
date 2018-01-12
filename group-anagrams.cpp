/* LC 49
 * Given an array of strings, group anagrams together.
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
 * Note: All inputs will be in lower-case.
 */
 
 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;
        
        for(int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }
        
        for(auto it = m.begin(); it != m.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
    
    /* Tested.
     * Time complexity: O(n*m) where n is the number of strings and m is the length of the string.
     * Space complexity: O(n)
     */
