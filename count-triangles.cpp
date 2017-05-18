/* Given a list of line segment lengths, find the number of triangles that can be formed using them.
 * A triangle should satisfy: a+b > c, b+c > a and a+c > b
 */
 
 #include<iostream>
 #include<vector>
 using namespace std;
 
 int count(vector<int> &A) {
        int n = A.size(),c = 0;
        if(n < 3) return 0;
        sort(A.begin(),A.end());
        for(int i = 0; i < n-2; i++) {
                int k = i+2;
                for(int j = i+1; j < n-1; j++) {
                        while(k<n && A[i] >  A[k]-A[j]) k++;
                        c += k-j-1;
                }
        }
        return c;
}

/* Not tested thoroughly but is present as part of gfg.
 * Time complexity: O(n^2) where n is the number of segments.
 * Space complexity: O(1)
 */
