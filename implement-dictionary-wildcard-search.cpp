/* LC 211
 * Design a data structure that supports the following two operations:
 * void addWord(word)
 * bool search(word)
 * search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 * For example:
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 */
 
 class WordDictionary {
typedef struct TrieNode {
        bool isEnd;
        unordered_map<char,struct TrieNode*> children;
        TrieNode(){
            this->isEnd = false;
        }
}TrieNode;
TrieNode *root = NULL;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if(!root){
            root = new TrieNode();
        }
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++) {
            if(cur && cur->children.find(word[i]) == cur->children.end()){
                TrieNode* newNode = new TrieNode();
                cur->children[word[i]] = newNode;
            }
            cur = cur->children[word[i]];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool helper(string word,TrieNode *root) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            if(cur && cur->children.find(word[i]) != cur->children.end()) {
                cur = cur->children[word[i]];
            } else if (cur && word[i] == '.') {
                TrieNode *tmp = cur;
                for(auto c : tmp->children) {
                    cur = c.second;
                    if(helper(word.substr(i+1), cur)) {   
                        return true;
                    }
                }
                return false;
            } else {
                return false;
            }
        }
        return cur && cur->isEnd;
    }
    
    bool search(string word) {
        return helper(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
 
 /* Tested.
  * Time complexity: Search (O(nm)) if there are wildcharacters
  * Space complexity: O(nm)
  */
