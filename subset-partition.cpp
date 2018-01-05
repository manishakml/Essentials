/* Given an array and a target, find the number of subsets that sum up to the target. */

int helper(vector<int> &A, int k, int idx) {
  if(idx >= A.size()){
    return 0;
  }
  return (A[idx] == k? 1 : 0) + helper(A,k,idx+1) + helper(A,k-A[idx],idx+1); //if elem equals sum, add 1; count n_subsets including elem and n_subsets excluding element and add them.
}

int subset_count(vector<int> &A, int k){
  return helper(A,k,0);
}

/* Not tested.
 * Note: (1,2,3,4) and target 4: 
 * Time complexity: Exponential
 * Space complexity: O(n)
 */
