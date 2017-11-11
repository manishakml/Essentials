/* Given a string, count the number of palindromic subsequences in it. */

#include<iostream>
#include<vector>
using namespace std;

int countPalindromes(string s) {
    int n = s.length();
    vector<vector<int> > A(n,vector<int>(n,0));

    for(int i = 0; i < n; i++) {
        A[i][i] = 1;
    }

    for(int L = 2; L <= n; L++) {
        for(int i = 0; i < n-L+1; i++){
            int j = i+L-1;
            if(s[i] == s[j]){
                A[i][j] = A[i+1][j] + A[i][j-1] + 1;
            } else {
                A[i][j] = A[i+1][j] + A[i][j-1] - A[i+1][j-1];
            }
        }
    }
    return A[0][n-1];
}

int main() {
    string s;
    cout << "Enter str:";
    cin >> s;
    cout << "\n Result:" << countPalindromes(s);
    return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(n^2) where n is the string length.
 * Space complexity: O(n^2)
 */
