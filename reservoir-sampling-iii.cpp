/* Given an array of unique elements and a frequency array which denotes the frequency with which that element occurs, output an element randomly. */

int random(vector<int> &A, vector<int> &f){
  int n = A.size();
  int m = f.size();
  if(n == 0 || m == 0 || n != m){
    return INT_MAX; // or throw some exception
  }
  int res = -1; //any default value will do, since it will definitely get init'd before the fn. returns
  int sum = 0;
  for(int i = 0; i < A.size(); i++){
    sum += f[i];  //keep track of count of the number of elements
    int r = rand()%sum; // random over the number of elements seen so far
    if(r < f[i]){ //r falls 0 and f[i], so this element gets f chances of being the res
      res = A[i];
    }
    return res;
  }
  
  /* Not tested.
   * Time: O(n)
   * Space: O(1)
   */
