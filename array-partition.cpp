/* Determine if a given array can be partitioned into k subsets with equal sum */
#include<iostream>
#include<vector>
using namespace std;

bool helper(const vector<int> &A, int n, int idx, int target, vector<vector<int>> &B){
    if(idx == n){
        for(int i = 0; i < B.size(); i++) {
            if(B[i][0] != target || B[i][1] <= 0) {
                return false;
            }
        }
        return true;
    }

    int val = A[idx];
    for(int i = 0; i < B.size(); i++){
        B[i][0] += val;
        B[i][1] += 1;
        cout << "A:"<<i << " " << B[i][0] << " " << B[i][1] << endl;
        if(helper(A,n,idx+1,target,B)) return true;
        B[i][0] -= val;
        B[i][1] -= 1;
        cout << "B:"<<i << " " << B[i][0] << " " << B[i][1] << endl;
    }
    return false;
}

bool partition(const vector<int> &A, const int k) {
    int n = A.size();
    if(n == 0 || k <= 0 || k > n) return false;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += A[i];
    }

    if(sum % k) return false;
    vector<vector<int>> B(k, vector<int>(2,0));
    return helper(A,n,0,sum/k,B);
}

int main() {
    const vector<int> A = {4,3,2,3,5,2,1};
    int k = 4;
    cout << partition(A,k);
    return 1;
}

/* Not tested thoroughly.
 * Approach above is backtracking. Run the program to see how it works.
 * Time complexity: O(kn!) - to be verified.
 * Space complexity: O(kn) - to be verified.
 */
