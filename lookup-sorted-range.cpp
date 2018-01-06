/* Given an array of characters and a target character, find the lowest character in the array greater than the target. If target is greater than the last element, wrap around */

#include<iostream>
#include<vector>
using namespace std;

int min_idx(vector<char> &A, char target){
    int n = A.size();
    if( n == 0 ) return -1;
    if (target < A[0]) return 0;
    if(target > A[n-1]) return 0;

    int l = 0, r = n-1;

    while(l <= r) {
        int m = l + (r-l)/2;
        if(A[m] == target || (m != n-1 && A[m] < target && A[m+1] > target)){
            return m+1;
        } else if(A[m] < target) {
            l = m+1;
        } else {
            r = m;
        }
    }
    return -1;
}

int main(){
    vector<char> A = {'c','f','k'};
    char target = 'd';
    cout << min_idx(A,target);
    return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(log n) where n is the number of elements in the list.
 * Space complexity: O(1)
 */
