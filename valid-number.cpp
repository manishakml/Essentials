/* LC 65
 * Validate if a given string is numeric.
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */

#include<iostream>
using namespace std;

class Solution {
    bool isNum(char c) {return c >= '0' && c <= '9';}
    bool isSgn(char c) {return c == '-' || c == '+';}
    bool isDot(char c) {return c == '.';}
    bool isE(char c) {return c == 'e' || c == 'E';}
    bool isSpc(char c) {return c == ' ';}
public:
    bool isNumber(string s) {
        bool haveNum=false; int i = 0,n=s.length();
        //check spaces
        while(i<n && isSpc(s[i]))i++;
        //check sign
        if(i<n && isSgn(s[i]))i++;
        //check num before dot
        while(i<n && isNum(s[i])){haveNum=true;i++;}
        //check dot
        if(i<n && isDot(s[i]))i++;
        //check num after dot
        while(i<n && isNum(s[i])){haveNum=true;i++;}
        //check e
        if(i<n && isE(s[i]) && haveNum) {
            haveNum=false;i++;
            //check sign after e
            if(i<n && isSgn(s[i]))i++;
        }
        //check num after e
        while(i<n && isNum(s[i])){haveNum=true;i++;}
        //check spaces
        while(i<n && isSpc(s[i]))i++;
        return i==n && haveNum;
    }
};

//Approach 2 - simpler

class Solution {
public:
    bool isNumber(string s) {
        int r = s.length()-1;
        
        while(r >= 0 && s[r] == ' '){
            r--;
        }
        if(r < 0) {
            return false;
        }
        s.erase(s.begin()+r+1, s.end());
        r = 0;
        while(r < s.length() && s[r] == ' '){
            r++;
        }
        if(r == s.length()) {
            return false;
        }
        bool numberSeen = false;
        bool eseen = false;
        bool pointseen = false;
        bool numberAftere = true;
        for(int i = r; i < s.length(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                numberSeen = true;
                numberAftere = true;
            } else if( s[i] == '.'){
                if(pointseen || eseen) {
                    return false;
                }
                pointseen = true;
            } else if(s[i] == 'e'){
                if(eseen || !numberSeen) {
                    return false;
                }
                eseen = true;
                numberAftere = false;
            } else if( s[i] == '+' || s[i] == '-') {
                cout << "MK";
                if(i != 0 && s[i-1] != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        return numberSeen && numberAftere;
    }
};

/* Tested.
 * Time complexity: O(n) where n is the number of elements in the string.
 * Space complexity: O(1)
 */
