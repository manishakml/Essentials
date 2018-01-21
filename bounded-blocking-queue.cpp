/* Implement a thread-safe bbq */
template<class T>
class BBQ{
  int sz_;
  int curSz_ = 0;
  list<T> q;
  std::mutex mutex_;
  std::mutex mutex1_;
  std::condition_variable hasElement_, hasSpace_;
public:
  BBQ(int size){sz_ = size;}
  void push(T a){
    std::unique_lock<std::mutex> wlock(mutex1_);
    std::unique_lock<std::mutex> mlock(mutex_);   //ctor locks based on the mutex
    while(curSz_ >= sz_){
      hasSpace.wait(mlock);
    }
    q.push_back(a);
    curSz++;
    hasElement.notify_one();
    mlock.unlock();
    wlock.unlock();
  }
  
  T pop(){
    std::unique_lock<std::mutex> mlock(mutex_);
    while(curSz_ <= 0){
      hasElement.wait(mlock);
    }
    T res = q.front();
    q.pop_front();
    curSz--;
    hasSpace.notify_one();
    mlock.unlock();
  }
  
  //this needs push() to be bound by 2 locks; otherwise push neednt have 2 locks. order of the locks should be maintained in both methods. order of locking and unlocking should be maintained.
  void multiPush(vector<T> elements){
    std::unique_lock<std::mutex> wlock(mutex1_);
    std::unique_lock<std::mutex> mlock(mutex_);
    for(T e : elements){
      while(curSz_ >= sz_) {
        hasSpace.wait(mlock);
      }
      q.push_back(e);
      curSz++;
      hasElement.notify_one();
    }
    mlock.unlock();
    wlock.unlock();    
  }
};
