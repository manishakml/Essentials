/* Reverse words in a string and preserve all whitespaces, multispaces, leading and trailing spaces. */

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void reverse_S(string &s) {
    int n = s.length();
    if(n < 2) return;
    reverse(s.begin(),s.end());
    int r = 0, start = 0;

    while(r < n) {
        while(r < n && s[r] == ' ') r++;
        if(r == n) return;
        start = r;

        while(r < n && s[r] != ' ') r++;
        reverse(s.begin()+start, s.begin()+r);
        start = r+1;
    }
}

int main(){
    string s = "     ";
    //cout << "Enter str:";
    //cin >> s;
    reverse_S(s);
    cout << endl << "Start" << s <<  "End" << endl;
    return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
