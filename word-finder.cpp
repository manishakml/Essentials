/* Given a list of words and a list of characters, find an appropriate DS to store the words such that we can find all words from the dictionary that can be formed from a subset of chars from the given character list without reusing any character index.
 * Eg. {words, word, wood, order} and {orsdowe}, return {words,word,wood} but not {order}.
 */
 
 #include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

class Trie{
    public:
        unordered_map<char,Trie*> children;
        bool isEnd;
        Trie(){
            this->isEnd = false;
        }
};
Trie *head = NULL;

void init(unordered_set<string> &words){
    if(!head) {
        head = new Trie();
    }
    Trie *cur;
    for(const string &w : words){
        cur = head;
        for(const char &c : w) {
            if(cur && (cur->children.find(c) == cur->children.end())) {
                Trie* nn = new Trie();
                cur->children[c] = nn;
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }
}

void helper(unordered_set<string> &res, string r, Trie *cur, unordered_map<char,int> &m){
    if(cur && cur->isEnd == true){
        res.insert(r);
    } else if(!cur) {
        return;
    }
    for(const pair<char,int> &p : m){
        if(cur && (cur->children.find(p.first) != cur->children.end())){
            if(p.second == 0) continue; //don't try to erase from map since it causes wrong references when it is in iteration loop
            m[p.first]--;
            helper(res,r+p.first,cur->children[p.first],m);
            m[p.first]++;
        }
    }
}

unordered_set<string> find(vector<char> &chars){
    unordered_map<char,int> m;
    unordered_set<string> res;
    string r = "";
    Trie *cur = head;
    if(!cur){
        return res;
    }
    for(const char &c : chars){
        m[c]++;
    }
    helper(res,r,cur,m);
    return res;
}

int main(){
    unordered_set<string> words = {"word","words","wood","order"};
    init(words);
    unordered_set<string> res;
    string s = "orsdowe";
    vector<char> v(s.begin(),s.end());
    res = find(v);
    for(const string &s : res) {
        cout << s << endl;
    }
}

/* Not tested thoroughly.
 * Time complexity: If the height of the tree (longest word in the dict.) is k, the length of char list is m and number of words in the dict. is n, we have to calc. number of nodes in the trie. n_nodes in a full BT of ht h is (2^h)-1. n_nodes = 2^0 + 2^1...2^(h-1). Multiple each side by 2; add/subtract 1 on RHS. 2*n_nodes = (2^1 +... 2^h +1)-1 = n_nodes + 2^h -1. Therefore, n_nodes = (2^h)-1.
   The ht. of the trie is 26^(k) - 1 if each node has 26 children and ht. of longest word is k. But it might iterate to the minimum of k or size of the char array m. Hence, (26^min(k,m)) - 1. But max children will be number of unique chars in char list = m-key. Therefore, (m-key^min(k,m)) + 1.
 * Space complexity: O(min(n_nodes, m-key)).
 */
 
