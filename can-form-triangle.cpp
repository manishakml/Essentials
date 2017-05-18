/* Given a list of line segments, are there any 3 segments that can form a triangle? If so, return the 3 segments.
 * A triangle can be formed by 3 segments a,b and c if:
 * a + b > c, b + c > a and a + c > b
 */
 
 #include<iostream>
 #include<vector>
 using namepsace std;
 
 vector<int> valid(vector<int> &A) {
        int n = A.size();
        vector<int> res;
        if(n < 3) return res;
        sort(A.begin(),A.end());
        for(int i = 0; i < n-2; i++) {
                if(A[i] > A[i+2] - A[i+1]) {
                        res.push_back(A[i]);
                        res.push_back(A[i+1]);
                        res.push_back(A[i+2]);
                        return res;
                }
        }
        return res;
}

/* Not tested thoroughly.
 * Note: Once sorted, it is sufficient to check only one out of the 3 conditions.
 * Note: This method relies on the fact that A...A'...B...C'...C => If A,B,C form a triangle, then A'BC' form a triangle too.
 * Time complexity: O(nlogn) where n is the number of segments.
 * Space complexity: O(1)
 */
