/* Given a flowerbed represented as 1s and 0s, 1 indicates a planted flower and 0 indicates a free slot, and given a number k, is it possible to plant k flowers in the bed such that no 2 flowers are adjacent? */

#include<iostream>
#include<vector>
using namespace std;
bool canPlant(vector<bool> &A, int k){
        if(k <= 0) {
                return true;
        }
        int n = A.size();
        if(n <= k) {
                return false;
        }

        for(int i = 0; i < n; i++){
                if(A[i] == 0 && ((i == 0 || A[i-1] == false) && (i == n-1 || A[i+1] == false))){
                        k--;
                        i++;
                } else if(A[i] == 1){
                        i++;
                }
        }
        return k == 0;
}

int main(){
        vector<bool> A = {0};
        int k = 2;
        cout << canPlant(A,k);
        return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(n)
 * Space: O(1)
 */
