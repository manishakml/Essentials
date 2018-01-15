/* LC 13
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include<iostream>
#include<string>
#include<map>
using namespace std;

int roman2int(string s) {
       unordered_map<char,int> m = {
                                        {'I',1},
                                        {'V',5},
                                        {'X',10},
                                        {'L',50},
                                        {'C',100},
                                        {'D',500},
                                        {'M',1000}
                              };
                                    
        int sum = 0;
        int n = s.length();
        if (!n) return sum;
       //check invalid char
        if(m.find(s.back()) == m.end()) return 0;
        sum += m[s.back()];
        /*if we want to check invalid input like IIII, we need to keep track of count
       int c = 1;
       */
        for(int i = n-2; i >= 0; i--) {
               //check invalid char
            if(m.find(s[i]) == m.end()) return 0;
               /*To keep track of illegal input like IIII
               if(m[s[i]] == m[s[i+1]]) {
                c++;
                if(c == 4) {
                        return 0;
                }
             } else {
                c = 1;
             }
             */
            if(m[s[i]] >= m[s[i+1]]){
                sum += m[s[i]];
            } else {
                sum -= m[s[i]];
            }
        }
        return sum;
}

/* Tested.
 * Time complexity: O(n) where n is the length of the string.
 * Space complexity: O(1) since map has constant number of elements.
 */
