/* Given a multi-dimensional array and an array of ints where each int represents the size of each dimension (MultiDimen A, vector<int> dimen) and also given a get(dimen) method where dimen represents an array of indices and get retrieves the value at that location, find the sum of all elements of the multi-dimensional array A.
 * Eg., let's have a multi-dimensional array A and a vector of dimension lengths(3,2,1). It looks somewhat like this: [[[7], [9]], [[-1], [0]], [[2], [4]]]. get(2,1,0) returns A[2][1][0] = 2.
 */
 #include<iostream>
 #include<vector>
 using namespace std;
 
 int sum(A, vector<int> &d) {
  int n = d.size();
  vector<int> idx(n,0);    //idx initially is {0,0,...n times}
  int s = get(idx);    // gets first nested value into sum;
  
  while(true) {
    int c = n-1;  //we need indices
    while(c >= 0) {
      idx[c]++;   //inc from 0 to size of that dimension eventually
      if(idx[c] == d[c]) {  //If dimension size is 5, idx moves from 0 to index 4.
        idx[c] = 0;
        c--;      // evaluate the next dimension (goes from lsb to msb)
      } else {
        s += get(idx);  //add it to running sum
        break;
      }
    }
    if(c < 0) {   //reached msb
      break;
    }
  }
  return s;
 }

//Easy recursive approach
void helper(MultiDimensionalArray &A, vector<int> &d, int &sum, int idx, vector<int> &idx_arr){
 if(idx == d.size()){
  sum += A.get(idx_arr);
 } else {
  for(int i = 0; i < d[idx]; i++){
   arr_idx.push_back(i);
   helper(A,d,sum,idx+1,idx_arr);
   arr_idx.pop_back();
  }
 }
}

int sum(MultiDimensionalArray &A, vector<int> &d){
 int sum = 0;
 vector<int> idx_arr;   //keep track of what indices to send to get();
 helper(A, d, sum, 0, idx_arr);
 return sum;
}
 
 /* Not tested.
  * Note: Work with an example to understand that it is essentially like enumerating bits, how we move from 000 to 001 to 010 etc.
  * Note: This can be parallelized by slicing across dimensions, evaluating each dimension on a different core for eg., and using an aggregator to get the final sum.
  * Time complexity: For an array with k dimensions, this algorithm takes O(2^k) time. More specifically, it takes 2^k * n time where n is the number of elements in the deepest dimension.
  * Space complexity: O(k).
  */
