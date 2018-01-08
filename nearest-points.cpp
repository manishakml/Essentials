/* Write a method to store a number of 2D points. Write another method to find k nearest points to a given center */

//Approach 1:
//Use an array to hold points. Use a custom comparator (pay heed to syntax) to sort points based on distance to center and return only first k points.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct point{
    int x;
    int y;
}Point;

vector<Point> P;

double dis(Point a, Point c) {
    return ((a.x-c.x)*(a.x-c.x)) + ((a.y-c.y)*(a.y-c.y));
}
void add(Point a) {
    P.push_back(a);
}
struct customCompare{
        customCompare(Point c) {this->c = c;}
        bool operator()(Point a, Point b){ return dis(a,c) < dis(b,c);}
        Point c;
};

vector<Point> nearest(Point c, int k){
    sort(P.begin(),P.end(),customCompare(c));
    P.erase(P.begin()+k,P.end());
    return P;
}

int main(){
    int n;
    Point a;
    cout << "\nEnter number of points to be added:";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "\nEnter point " << i+1 <<  "'s x and y:";
        cin >> a.x >> a.y;
        add(a);
    }
    Point c = {0,0};
    vector<Point> res = nearest(c,4);

    cout << "\n Nearest:\n";
    for(int i = 0; i < res.size(); i++){
        cout << res[i].x << " " << res[i].y << endl;
    }
    return 0;
}

// Approach 2 - note the syntax of custom comparator while using priority queue. Rest of the code remains same.
vector<Point> nearest(Point c, int k){
    priority_queue<Point, vector<Point>, customCompare> max_heap((customCompare(c)));
    for(int i = 0; i < P.size(); i++) {
        Point p = P[i];
        if(max_heap.size() == k) {
            Point t = max_heap.top();
            if(dis(p,c) < dis(t,c)){
                max_heap.pop();
                max_heap.push(p);
            }
        } else {
            max_heap.push(p);
        }
    }
    vector<Point> res;
    while(!max_heap.empty()) {
        res.push_back(max_heap.top());
        max_heap.pop();
    }
    return res;
}

//Approach 2 with lambda expressions
vector<Point> nearest(Point c, int k){
    auto cmp = [&c](Point a, Point b){return dis(a,c) < dis(b,c);};
    priority_queue<Point, vector<Point>, decltype(cmp)> max_heap(cmp);
    for(int i = 0; i < P.size(); i++) {
        Point p = P[i];
        if(max_heap.size() == k) {
            Point t = max_heap.top();
            if(dis(p,c) < dis(t,c)){
                max_heap.pop();
                max_heap.push(p);
            }
        } else {
            max_heap.push(p);
        }
    }
    vector<Point> res;
    while(!max_heap.empty()) {
        res.push_back(max_heap.top());
        max_heap.pop();
    }
    return res;
}
/* Not tested thoroughly.
 * Time complexity: Approach 1: O(nlogn) whre n is the number of points, Approach 2: O(nlogk) where k is the number of points requested.
 * Space complexity: Approach 1: O(n) for storing the points, none otherwise, Approach 2: O(n) for storing points, O(k) for priority_queue.
 */
