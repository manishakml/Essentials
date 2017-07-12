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
/* Not tested thoroughly.
 * Time complexity: O(nlogn) whre n is the number of points.
 * Space complexity: O(n) for storing the points, none otherwise.
 */
