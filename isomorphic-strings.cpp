/* LC 205
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 * For example,
 * Given "egg", "add", return true.
 * Given "foo", "bar", return false.
 * Given "paper", "title", return true.
 * Note:
 * You may assume both s and t have the same length.
 */
 #include <iostream>
 #include<string>
 using namespace std;
 
 bool isomorphic(string s, string t) {
  int m1[256] = {0}, m2[256] = {0}, n = s.length();
  for(int i = 0; i < n; i++) {
    if(m1[s[i] != m2[t[i]]) {
      return false;
    }
    m1[s[i]] = m2[t[i]] = i+1;
  }
  return true;
 }
      
 
/* Tested.
 * Time complexity: O(n) where n is the length of the string.
 * Space complexity: O(1).
 */

//Variations
//3 strings instead of 2. return true if all are isomorphic. No change in complexity
bool iso3(string s, string t, string u) {
    return isIsomorphic(s,t) && isIsomorphic(t,u);
}
//3 strings instead of 2. return true if any 2 are isomorphic. No change in complexity
bool iso3_1(string s, string t, string u) {
    return isIsomorphic(s,t) || isIsomorphic(t,u) || isIsomorphic(s,u);
}
// n strings. return true if all are isomorphic. Time complexity: O(n*m) = n strings of length m.
bool isoN(vector<string>& A) {
    bool res = true;
    for(int i = 0; i < A.size()-1; i++) {
        res &= isIsomorphic(A[i],A[i+1]);
    }
    return res;
}
  // n strings. return true if any pair is isomorphic . Time complexity: O(n^2m)       
bool isoN_1(vector<string>& A) {
        for(int i = 0; i < A.size()-1; i++) {
            for(int j = i+1; j < A.size(); j++) {
                 if(isIsomorphic(A[i],A[j]))
                     return true;
            }
        }
        return false;
}
// n strings. group isomorphic strings together. Time complexity: O(n^2m). Space complexity: O(nm) if we count in terms of individual chars.
vector<vector<string> > iso_group(vector<string> &A) {
    unordered_map<string,vector<string> > m;
    unordered_set<string> s;
    vector<vector<string> > res;
    for(int i = 0; i < A.size(); i++) {
        s.insert(A[i]);
    }
    for(int i = 0; i < A.size()-1; i++) {
        if(s.find(A[i]) == s.end()) continue;
        m[A[i]].push_back(A[i]);
        s.erase(A[i]);
        for(int j = i+1; j < A.size(); j++) {
            if(s.find(A[j]) == s.end()) continue;
            if(isIsomorphic(A[i],A[j])) {
                    m[A[i]].push_back(A[j]);
                    s.erase(A[j]);
            }
        }
    }
    if(!s.empty()) {
        m[A[A.size()-1]].push_back(A[A.size()-1]);
        s.erase(A[A.size()-1]);
    }
    for (unordered_map<string,vector<string> >::iterator it=m.begin(); it!=m.end(); ++it){
       res.push_back(it->second);
    }
    return res;
}
