/* Given a stream of integers and an integer k, get a random sample of k integers from the stream seen so far with each integer's probability same as its probability in the stream.
 * i.e., if there have been more (10% more) 1s and less 2s in the stream so far, the sample of k integers should probabcontain more (10% more) 1s and less 2s as well.
 */
 
 class Sampling {
 int k;
 int count = 0;
 Sampling(int k){
  vector<int> A(k,-1);
  this->k = k;
 }
 
 public:
 
 vector<int> sample(int a, int k){
    count++;
    if(A.size() < k) {
      A.push_back(a);
    } else {
      int r = rand()%count;
      if(r < k) {
        A[r] = a;
      }
    }
 }
 
 /* Not tested.
  * Time complexity: O(1)
  * Space complexity: O(k) if the result array is counted as extra space
  */
