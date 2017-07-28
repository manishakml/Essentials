/* LC 127
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * For example,
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
 */
 
 class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(string a: wordList) s.emplace(a);
        queue<string> q;
        q.push(beginWord);
        if(s.find(endWord) == s.end()){
            return 0;
        }
        
        if(s.find(beginWord) != s.end()) {
            s.erase(beginWord);
        }
        
        int c = 0;
        while(!q.empty()){
            int sz = q.size();
            c++;
            for(int i = 0; i < sz; i++){
                string t = q.front();
                q.pop();
                if(t == endWord) {
                    return c;
                }
                for(int j = 0; j < t.length(); j++){
                    string p = t;
                    for(int k = 0; k < 26; k++){
                        p[j] = 'a'+k;
                        
                          unordered_set<string>::iterator it = s.find(p);
                        
                          if(p!=t && it != s.end()){
                            q.push(p);
                            
                            s.erase(it);
                        }
                    }
                }
            }
            
        }
        return 0;
    }
};

//Approach 2 - using double ended bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s,head,tail, *ph, *pt;
        for(string a: wordList) s.emplace(a);
        if(s.find(endWord) == s.end()) return 0;
        
        head.emplace(beginWord);
        tail.emplace(endWord);
        
        int c = 1;
        while(!head.empty() && !tail.empty()){
            if(head.size()<tail.size()){
                ph = &head;
                pt = &tail;
            } else {
                ph = &tail;
                pt = &head;
            }
            c++;
            unordered_set<string> temp;
            for(auto it = ph->begin(); it != ph->end(); it++){
                string t = *it;
                s.erase(t);
                for(int j = 0; j < t.length(); j++){   
                    string p = t;
                    for(int k = 0; k < 26; k++){
                        p[j] = 'a'+k;
                          unordered_set<string>::iterator it = pt->find(p);
                          if(it != pt->end()) {
                              return c;
                          }
                          it = s.find(p);
                          if(it != s.end()) {
                            temp.emplace(p);
                            s.erase(p);
                        }
                    }
                }
            }
            swap(*ph,temp);
        }
        return 0;
    }
};

/* Tested.
 * Note 2: If a list of strings is given as dictionary, convert to a set.
 * Time complexity: O(n * length of word) where n is the dictionary size for approach 1.
 * Space complexity: O(n).
 */
