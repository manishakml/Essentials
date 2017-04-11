/* LC 76
 *  Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
 */
#include<iostream>
#include<string>
using namespace std;

string window(string s, string t) {
  int m1[128] = {};
  int m2[128] = {};
  //Note: int vector(128,0) can be used above too.
  int n = s.length(), m = t.length(), len = INT_MAX, j = 0, start = 0, count = 0;
  //mark the target counts
  for(int i = 0, i < m; i++) {
    m2[t[i]]++;
  }
  
  for(int i = 0, i < n; i++) {
    //if char not part of the target
    if(!m2[s[i]]) continue;
    m1[s[i]]++;
    //as long as we have not encountered minimum target length (applicable only for the first time)
    if(m1[s[i]] <= m2[s[i]]) count++;
    //found potential candidate
    if(count == m) {
      //prune the candidate
      while(!m2[s[j]] || m1[s[j]] > m2[s[j]]) {
        //prune the extra old char since marker is moving against it to the new found same char
        if(m1[s[j]] > m2[s[j]]) m1[s[j]]--;
        j++;
      }
      //update shortest length and begin-marker
       if(i-j+1 < len) {
         len = i-j+1;
         st = j;
       }
    }
  }
  return (len == INT_MAX)?"":s.substr(st,len);
}

/* Tested.
 * Time complexity: O(n) where n is the length of the main string. Note that the while loop does not add to the complexity since it moves only from previous marker point rather than loop entirely again.
 * Space complexity: O(1) since it is a fixed length bitmap.
 */
