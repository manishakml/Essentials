/* LC 10
 * Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

bool isMatch(string s, string p) {
        if(p.length() == 0) {
            return s.length() == 0;
        }
        
        if(p.length() > 1 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (s.length() != 0 && (s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1),p));
        } else {
            return s.length()!=0 && (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1),p.substr(1));
        }
    }

/* Tested.
 * Time complexity: Exponential
 * Space complexity: O(n)
 */
