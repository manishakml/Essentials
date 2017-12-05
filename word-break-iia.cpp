/* Given a string s and a dictionary implemented reasonably, find one valid breakdown of the string. */

#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;

string helper(string s, unordered_set<string> &d, unordered_map<string,string> &m){
    //if(m.find(s) != m.end()) return m[s];
    if(d.find(s) != d.end()) return s;
    string res = "";
    for(int sz = 1; sz < s.length(); sz++){
        string sub = s.substr(0,sz);
        if(d.find(sub) != d.end()){
            string str = helper(s.substr(sz),d,m);
            res = sub + " " + str;
            //m[s] = res;
            return res;   //One valid result found, return.
        }
    }
    //m[s] = res;
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
 * Time complexity: O(n!) without memoization
 * Space complexity: O(n)
 */
