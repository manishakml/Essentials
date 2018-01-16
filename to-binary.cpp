/* Convert a given number to binary */

#include<iostream>
#include<string>
using namespace std;

string toBinary(int n){
        string res = "";
        if(n < 0) {
                return res;
        }
        while(n){
                res += to_string(n%2);
                n /= 2;
        }
        reverse(res.begin(),res.end());
        return res;
}

int main(){
        cout << toBinary(38);
        return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */
