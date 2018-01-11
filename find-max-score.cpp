/* Given a list of lists, find out one element from each list such that element picked from list i should be strictly greater than element picked from list i-1. Find the max sum attainable. If no sum exists, return -1. */

#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int find_max2(vector<int> &A, int prev){
        int res = 0;
        for(int i = 1; i < A.size(); i++){
                if(A[i] > A[res] && A[i] < prev){
                        res = i;
                }
        }
        if(res == 0 && A[res] >= prev) {
                return -1;
        }
        return res;
}
int max_score(vector<vector<int> >& A){
        int sum = 0, prev = INT_MAX;
        for(int i = A.size()-1; i >= 0; i--){
                vector<int> B = A[i];
                int j = find_max2(B,prev);
                if(j == -1){
                        return -1;
                }
                prev = B[j];
                sum += prev;
        }
        return sum;
}

int main(){
        vector<vector<int> > A = {
                                        {3,1,2},
                                        {4,5,6},
                                        {9,8,7}
                                 };

        cout << max_score(A);
        return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(n*m) where n is the number of lists and m is the size of the list.
 * Space complexity: O(1)
 */

