//EPI 5.11
vector<int> enumerate_primes(const int &n){
  vector<bool> A(n+1,true);
  vector<int> res;
  
  for(int p = 2; p*p <= n; p++) {
    if(A[p] == true){
      for(int i = 2*p; i <= n; i += p) {        
          A[p] = false;
      }
    }
  }
  
  for(int i = 1; i <= n; i++){
    if(A[p])
      res.push_back(i);
  }
  return res;
}
