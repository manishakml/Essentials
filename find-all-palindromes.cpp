/* Given a string, find all palindromic subsequences in it */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordrered_set>
using namespace std;
unordered_map(string,unordered_set<string>> m;
unordered_set<string> findPalindromes(string s){
    unordered_set<string> res;
    if(m.find(s) != m.end()){
        res = m[s];
        return res;
    }
    int n = s.length();
    if(n <= 1){
        res.insert(s);
        return res;
    }

    unordered_set<string> A = findPalindromes(s.substr(0,n-1));
    unordered_set<string> B = findPalindromes(s.substr(1,n-1));
    for(const string &a : A) {
        res.insert(a);
    }
    for(const string &b : B){
        res.insert(b);
    }
    if(s[0] == s[n-1]){
        unordered_set<string> tmp = findPalindromes(s.substr(1,n-2));
        string a = s.substr(0,1);
        for(const string t& : tmp){
            res.insert(a+t+a);
        }
        res.insert(a+a);
    }
    m[s] = res;
    return res;
}

/* Not tested thoroughly.
 * Time complexity: O(3^n). Consider it like a tree.
            n
         /  \   \
        n-1  n-1 n-2
        ..
        ..
        0
  * n-length string makes 3 calls at max to n-1, n-1 and n-2 length strings.
  * So, this makes a tree of height n. Theredore, number of nodes is 3^n and hence, that's the time complexity.
  * Space complexity: O(n) - height of the call tree.
  */
