/* Given n closed lockers and n students, student 1 opens all lockers, student 2 opens 2,4,6...lockers, student 3 opens 3,6,9...lockers and so on. After the students are done, what are the lockers that are open? */

#include<iostream>
#include<vector>
using namespace std;

void openLocker(int n){
        vector<bool> locker(n+1);       //initially all are false, indicating they are closed
        for(int i = 1; i <= n; i++) {   //for each student
                for(int j = i; j <= n; j+=i) {  //for each locker they touch (always >= their turn. Eg. 3rd student touches only locker 3 onwards
                        locker[j] = !locker[j]; //switch the state
                }
                if(locker[i] == true){
                        cout << i;
                }
        }
}

int main(){
        openLocker(100);
        return 1;
}

/* Not tested thoroughly.
 * Note: For a door to be open, it should have been touched odd number of times (eg: OCO or OCOCO since the first operation is open). For a number to be a perfect sqr, it should have odd number of divisors. Hence, all the perfect squares <= n are valid answers. This is the O(1) space and O(n) time approach */
 * Time: O(n^2)
 * Space : O(n)
 */
