/* LC 151
 * Given an input string, reverse the string word by word.
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string. 
 */
 
 #include<iostream>
 #include<string>
 using namespace std;
 
 //similar to reverse-words-iii except for corner case handling and return type handling.
 void reverseWords(string &s) {
        int n = s.length(), r = 0, w = 0, start = 0;
        if(!n) return;
        reverse(s.begin(), s.end());
        
        while(r < n) {
            while(r < n && s[r] == ' ') r++;
            if(r == n) break;
            while(r < n && s[r] != ' ') {
                s[w++] = s[r++];
            }
            if(w < n-1) s[w] = ' ';
            reverse(s.begin()+start, s.begin()+w);
            start = ++w;
        }
        w?s.erase(s.begin()+w-1, s.end()):s.erase(s.begin(),s.end());
    }
    
    /* Tested.
     * Time complexity: O(n) where n is the string length
     * Space complexity: O(1)
     */
