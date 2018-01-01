/* Determine if a given array can be partitioned into k subsets with equal sum */
#include<iostream>
#include<vector>
using namespace std;

bool helper(const vector<int> &A, int n, int idx, int target, vector<vector<int>> &B){
    //if at the end of the array
    if(idx == n){
        for(int i = 0; i < B.size(); i++) {
            //if some bucket has not reached target or if all elements are over and distributed correctly to <k buckets,i.e some bucket is empty
            if(B[i][0] != target || B[i][1] <= 0) {
                return false;
            }
        }
        return true;
    }
//this iteration's element
    int val = A[idx];
    for(int i = 0; i < B.size(); i++){
        //add the cur val to the cur bucket
        B[i][0] += val;
        //increase the number of elem in the cur bucket
        B[i][1] += 1;
        if(helper(A,n,idx+1,target,B)) return true;
        //undo addition and try adding them into the next bucket, if any
        B[i][0] -= val;
        B[i][1] -= 1;
    } //if all buckets are done, return false in this iteration and retract to previous iteration
    return false;
}

bool partition(const vector<int> &A, const int k) {
    int n = A.size();
    if(n == 0 || k <= 0 || k > n) return false;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += A[i];
    }
//sum has to be evenly divisible by buckets for it to fit in k buckets evenly
    if(sum % k) return false;
    //B[i][0] keeps the val/sum at ith bucket. B[i][1] keeps the number of elems that contributed to the val/sum in ith bucket
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
 * Time complexity: O(k^n) - Draw the recursion tree. Looks like a binary tree with k children since each element tries to fit in all of the k buckets.
 * Space complexity: O(max(k,n))
 */
