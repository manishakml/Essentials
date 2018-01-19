/* Given a stream of messages coming in the form of bursts (with gaps between them) and a threshold time, a burst is defined as the series of messages received before a gap = threshold. As soon as a burst occurs, identify the last message in it. */
char = message
- = gap
threshold = 3
a--b-cd-e---<return e here>
*/

//each message has to attempt to wait for 'threshold' until it can return true. When another message comes before the threshold has passed for the previous message, the previous msg should be notified and return false. The second message should now wait. This process should go on until any message has passed its threshold without interruption. */
class MSB{
long threshold_;
std::condition new_arrival;
std::mutex mutex_;
public:
MSB(long s){ threshold_ = size;}
bool process(Obj message){
    {std::unique_lock<std::mutex> mlock(mutex_);
    new_arrival.notify_all();
    if(new_arrival.wait_for(mlock, threshold)){
      return true;
    }
    return false;
    }
}

//identify the last n messages in the burst
class MSB{
long threshold_;
vector<std::condition_variable> new_arrivals_;
std::mutex mutex_;
int n_;
public:
MSB(long s, int n){ threshold_ = size; n_ = n; new_arrivals_.resize(n);}
bool process(Obj message){
    {std::unique_lock<std::mutex> mlock(mutex_);
    for(auto condition: new_arrivals_){
      condition.notify_all();
      if(condition.wait_for(mlock, threshold)){
        return true;
      }
    }
    return false;
    }
}


