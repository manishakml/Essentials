/* LC 295
 * Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 * Examples: 
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * Design a data structure that supports the following two operations:
 * void addNum(int num) - Add a integer number from the data stream to the data structure.
 * double findMedian() - Return the median of all elements so far.
 * For example:
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 */
 
 class MedianFinder {
 /* Consider the stream forming a sorted array like this ----A----+|---B----
    The vertical bar represents median. A has elem lower than median and B has greater.
    We are only intereted in the '+' element since the median is either the vertical bar (odd elements) or the combination of vertical bar and plus(even elements).
    So, we keep a max_heap to keep track of highest in A and min_heap to keep track of lowest in B.
    Finally, if both heaps are same sized, we take the avg of the top elements (| and  +). If one is greater than the other, we take the top of that (|).
  */  
    priority_queue<int,vector<int>> max_heap;
    priority_queue<int,vector<int>,std::greater<int>> min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {       
    }
    
    void addNum(int num) {
        if(max_heap.empty() || num < max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        //rebalance the heap. We are keeping 2 balanced heaps, since median divides a sorted array into 2 equal halves.
        if(max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if(min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        int n = min_heap.size() + max_heap.size();
        if(n%2 != 0) {
            return min_heap.size()>max_heap.size()? min_heap.top() : max_heap.top();
        } else if(n != 0) {
            return (min_heap.top() + max_heap.top())/2.0;
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
 
 /* Tested.
  * Time complexity: Add - O(log n) where n is the size of the heap, find - O(1)
  * Space complexity: O(n)
  */
