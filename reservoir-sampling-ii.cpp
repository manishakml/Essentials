/* Given a stream of integers and an integer k, get a random sample of k integers from the stream seen so far with each integer's probability same as its probability in the stream.
 * i.e., if there have been more (10% more) 1s and less 2s in the stream so far, the sample of k integers should probabcontain more (10% more) 1s and less 2s as well.
 */
 
 class Sampling {
 int k;
 int count = 0;
  vector<int> A;
 Sampling(int k){
  A(k,-1);
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
  * Note: Chance of the incoming element replacing a slot = k/n (out of n random slots, there are k slots that can be replaced). Similarly, consider an elm that went into the array in last round. So, it replaced an element with chance k/n-1 (since there were n-1 elem then). The chance that it won't be replaced this round, is 1-(1/n) since there are 1/n slot options for the current elem.. So, the chance of the prev elem in the arr gets updated to chance of it having entered the arr * chance of it not being replaced this round = k/(n-1) * (1-(1/n)) = k/n. So, it's probability got updated from k/n-1 to k/n. Also, the incoming elem has the probability of k/n to enter the array (the aim was to establish them being equal).
  * Time complexity: O(1)
  * Space complexity: O(k) if the result array is counted as extra space
  */
