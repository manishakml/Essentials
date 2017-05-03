/* LC 186
 *  Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
 * The input string does not contain leading or trailing spaces and the words are always separated by a single space.
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * Could you do it in-place without allocating extra space?
 */
 
 #include<iostream>
 #include<string>
 using namespace std;
 
 void reverseWords(string &s) {
        int n = s.length();
        if(n < 2) return;
        reverse(s.begin(),s.end());
        int start = 0;
        for(int i = 0; i <= n; i++) {
            if(i == n || s[i] == ' ') {
                reverse(s.begin()+start, s.begin()+i);
                if(i < n-1) start = i+1;
            }
        }
        
    }
    
    /* Tested.
     * Note: This is simpler version of the question.
     * Time complexity: O(n) where n is the number of characters in the string.
     * Space complexity: O(1)
     */
