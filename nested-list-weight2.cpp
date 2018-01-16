/* LC 364
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 * Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
 * Example 1:
 * Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)
 * Example 2:
 * Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
 */
 #include <iostream>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 
 int getD(vector<NestedInteger>& A) {
        if(A.size() == 0){
            return 0;
        }
        int d = 0;
        for(NestedInteger& a : A) {
            if(!a.isInteger()) {
                d = max(d,getD(a.getList()));
            }
        }
        return d+1;
    }
    
    int helper(vector<NestedInteger>& A, int d) {
        int sum = 0;
        for(NestedInteger& a: A) {
            if(a.isInteger()) {
                sum += a.getInteger() * d;
            } else {
                sum += helper(a.getList(), d-1);
            }
        }
        return sum;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int d = getD(nestedList);
        return helper(nestedList, d);
    }

//Iterative
int getD(const vector<NestedInteger> &A) {
        queue<NestedInteger> q;
        int d = 0;
        for (NestedInteger a: A) {
            q.push(a);
        }
 
        while(!q.empty()) {
            d++;
            int size = q.size();
            for(int i = 0 ; i < size; i++) {
                NestedInteger tmp = q.front();
                q.pop();
                if(!tmp.isInteger()) {
                    for(NestedInteger t: tmp.getList()) {
                        q.push(t);
                    } 
                }
            }
        }
        return d;
   }

    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int d = getD(nestedList);
        queue<NestedInteger> q;
        int sum = 0;
        for (NestedInteger a: nestedList) {
            q.push(a);
        }
 
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0 ; i < size; i++) {
                NestedInteger tmp = q.front();
                q.pop();
                if(tmp.isInteger()) {
                    sum += tmp.getInteger() * d;
                } else {
                    for(NestedInteger t: tmp.getList()) {
                        q.push(t);
                    }
                }
            }
            d--;
        }
        return sum;
    }

//reverse depth without extra depth calculation
//if we have (a,(b,(c))). Reverse depthsum = 3a+2b+c. Depth sum = a+2b+3c. Reverse depthsum = 4(a+b+c) - (a+2b+3c) = (depth+1)(regular_sum) - depthSum.
int rSum;
int maxDepth;
int helper3(vector<NI> &A, int d){
        int dSum = 0;
        for(int i = 0; i < A.size(); i++){
                if(A[i].isInteger()){
                        rSum += A[i].getInteger();
                        dSum += A[i].getInteger() * d;
                } else {
                        dSum += helper3(A[i].getList(),d+1);
                        maxDepth = max(maxDepth,d+1);
                }
        }
        return dSum;
}
int reverseDepth(vector<NI> &A){
        if(A.size() == 0) {
                return 0;
        }
        rSum = 0;
        maxLevel = 1;
        int dSum = helper3(A,1);
        return (maxDepth+1)*rSum - dSum;
}
    
    /* Tested.
     * Time complexity: O(n) where n is the number of elements after decomposition.
     * Space complexity: O(n) for the call stack.
     */
