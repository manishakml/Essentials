/* Given a list of line segment lengths, get all the triplets that form a triangle */

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > tri(vector<int> &A) {
        vector<vector<int> > answer;
        int n = A.size(),c = 0;
        if(n < 3) return answer;
        sort(A.begin(),A.end());
        for(int i = 0; i < n-2; i++) {
                int k = i+2;
                for(int j = i+1; j < n-1; j++) {
                        while(k<n && A[i] >  A[k]-A[j]) {
                                if(j != k) {
                                        vector<int> res;
                                        res.push_back(A[i]);
                                        res.push_back(A[j]);
                                        res.push_back(A[k]);
                                        answer.push_back(res);
                                }
                                k++;
                        }
                        //c += k-j-1;
                }
        }
        return answer;
}

/* Not thoroughly tested - modified gfg algorithm.
 * Time complexity: O(n^2) where n is the number of line segments.
 * Space complexity: O(1)
 */
