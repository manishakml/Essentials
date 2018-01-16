/* Given a string, find the number of holes in it. letters A,D,O,P,Q,R have one hole, letter B has 2 holes. Rest have no holes. */

#include<iostream>
#include<string>
using namespace std;


int holes(string s){
        int count = 0;
        for(int i = 0; i < s.length(); i++){
                if(s[i] == 'A' || s[i] == 'D' || s[i] == 'O' || s[i] == 'P' || s[i] == 'Q' || s[i] == 'R'){
                        count++;
                } else if(s[i] == 'B') {
                        count += 2;
                }
        }
        return count;
}


int main(){
        string s = "ABCDEFG";
        cout << holes(s);
        return 1;
}

/* Not tested thoroughly
 * Note: this can be extended for lower case. This can be extended for all characters if we have a mapping beforehand.
 * Time: O(n)
 * Space: O(1)
 */
