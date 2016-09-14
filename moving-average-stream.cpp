/**
 * Leetcode 346
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 * For example:
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 */
 
 #include<iostream>
 
 using namespace std;
 
 class MovingAverage {
    int ws;
    queue<int> q;
    
    MovingAverage(int size) {
       ws = size;
    }
    
    double next(int x) {
       static int sum = 0;
       if(q.size() == ws) {
          sum -= q.front();
          q.pop();
          sum += x;
          q.push(x);
          return (double)sum/ws;
       }
       sum += x;
       q.push(x);
       return (double)sum/q.size();
    }
 }
 
 /**
  * Time complexity:   O(1) for every input.
  * Space complexity : O(w) where w is the window size.
  * Not tested.
  */
    
