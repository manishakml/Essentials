/* Given a string s and a dictionary implemented reasonably, find one valid breakdown of the string. */

#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;

string helper(string s, unordered_set<string> &d, unordered_map<string,string> &m){
    //if previously computed in prev. recursive calls, use that result.
    if(m.find(s) != m.end()) return m[s];
    //if it's a dictionary word, use that result. We return because we need only one combination.
    if(d.find(s) != d.end()) return s;
    string res = "";
    for(int sz = 1; sz < s.length(); sz++){
        //substring of incremental sizes which becomes the prefix
        string sub = s.substr(0,sz);
        if(d.find(sub) != d.end()){
            //suffix
            string str = helper(s.substr(sz),d,m);
            res = sub + " " + str;
            //store it for future use
            m[s] = res;
            return res;   //One valid result found, return.
        }
    }
    //store res as ""
    m[s] = res;
    return res;
}

string wb(string s, unordered_set<string> &d) {
    unordered_map<string,string> m;
    return helper(s,d,m);
}

int main(){
    string s;
    cout << "S:";
    cin >> s;

    unordered_set<string> d = {"leet","code"};
    cout << endl << wb(s,d);
    return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(n!). Memoization avoid re-solving few of the same subproblems. Consider "xyzxyabc" and {xyz,xy,z}. First recursive call (sz = 2): xy z xy "" So, map has {{abc,""},{xyabc,xy},{zxyabc,z xy},{xyzxyabc,xy z xy}}. 2nd recursive call (sz = 3): xyz helper(xyabc) = xyz (from map)xy.
 * Space complexity: O(n)
 */
