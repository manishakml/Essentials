/* Implement a circular queue */
template <class T>
class CQ{
  int sz_;
  int f = -1, r = -1;
  vector<int> A;
 public:
   CQ(int size) {
    sz_ = size;
    A.resize(sz_);
   }
   
   void push(T a){
    if(f == (r+1) % sz_) {
      cout << "Queue full!";
      return;
    }
    r = (r+1)%sz_;
    A[r] = a;
    if(f == -1) {
      f++;
    }
   }
   
   T pop(){
    if(f == -1){
      cout << "Queue empty!";
      return;
    }
    T res = A[f];
    if(f == r){ //only element
      f = -1;
      r = -1;
    } else {
      f = (f+1)%sz_;
    }
    return res;
   }
};
