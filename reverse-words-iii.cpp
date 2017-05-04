/* LC 557
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 * Example 1:
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */
 
 #include<iostream>
 #include<string>
 using namespace std;
 
 string reverseWords(string s) {
        int n = s.length(), start = 0;
        if(n < 2) return s;
        int w = 0, r = 0;
        while(r < n) {
            while(r < n && s[r] == ' ') r++;
            while(r < n && s[r] != ' ') {
                s[w++] = s[r++];
            }
            if(w < n-1) s[w] = ' ';
            reverse(s.begin()+start, s.begin()+w);
            start = ++w;
        }
        return s.substr(0, w-1);
    }
    
    /* Tested.
     * Note: We have to compact spaces - hence w & r. We have to return substr in the end to remove unnecessary chars.
     * Time complaxity: O(n) where n is the number of characters in the string.
     * Space complexity: O(1)
     */
