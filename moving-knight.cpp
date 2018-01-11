/* Given an nxn chess board, a start position and an end position, what is the min steps for a knight to move form start to end. A knight has 8 valid moves: (-2, -1), (-1, -2), (2, -1), (1, -2), (1, -2), (-2, 1), (1, 2), (2, 1) */

#include<iostream>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;

typedef struct Point{
    int x;
    int y;
}Point;

vector<int> X = {-2,-1, 2, 1, 1,-2,1,2};
vector<int> Y = {-1,-2,-1,-2,-2, 1,2,1};

bool isSafe(Point p, vector<int> X, vector<int> Y, int k, int n, unordered_set<Point> &discard){
    int x = p.x+X[k];
    int y = p.y+Y[k];
    Point t;
    t.x = x; t.y = y;
    if(x < 0 || x > n-1 || y < 0 || y > n-1 || discard.find(t) != discard.end()){
        return false;
    }
    return true;
}

int knight(int n, Point s, Point e){
    int c = 0;
    auto cmp = [](Point a, Point b){return a.x == b.x && a.y == b.y;};
    unordered_set<Point,decltype(cmp)> head(cmp), tail(cmp), discard(cmp), *ph, *pt;
    head.insert(s);
    tail.insert(e);

    while(!head.empty() && !tail.empty()){
        if(tail.size() < head.size()){
            ph = &tail;
            pt = &head;
        } else {
            ph = &head;
            pt = &tail;
        }

        unordered_set<Point,decltype(cmp)> temp(cmp);

        for(auto it = ph->begin(); it != ph->end(); it++){
            Point t = *it;
            if(pt->find(t) != pt->end()) {
                return c;
            }
            discard.insert(*it);
            for(int k = 0; k < 8; k++){
                if(isSafe(t,X,Y,k,n,discard)){
                    Point p;
                    p.x = t.x+X[k];
                    p.y = t.y+Y[k];
                    temp.insert(p);
                }
            }
        }
        c++;
        swap(temp,*ph);
    }
    return c;
}

int main(){
    int n = 6;
    Point s,e;
    s.x = 4; s.y = 5;
    e.x = 1; e.y = 1;
    cout << knight(n,s,e);
    return 1;
}

//with queue, returning count
int knight(int n , Point s, Point e){
    queue<Point> q;
    q.push(s);
    int c = 0;
    unordered_set<Point> discard;
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            Point t = q.front();
            q.pop();
            if(t == e){
                return c;
            }
            discard.insert(t);
            for(int k = 0; k < 8; k++){
                if(isSafe(t,X,Y,k,n,discard)){
                    Point p;
                    p.x = t.x+X[k];
                    p.y = t.y+Y[k];
                    q.push(p);
                }
            }
        }
        c++;
    }
    return c;
}

void populate(vector<Point> res, pair<Point*, Point> t) {
    while(t->first != sentinal){
        res.push_back(t.second);
        t = t->first;
    }
}
//with queue, returning path
vector<Point> knight(int n , Point s, Point e){
    vector<Point> res;
    queue<pair<Point*, Point>> q;
    Point sentinel;
    sentinel.x = -1;
    sentinel.y = -1;
    q.push(make_pair(&sentinel,s));
    int c = 0;
    unordered_set<Point> discard;
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            pair<Point*, Point> t = q.front();
            q.pop();
            if(t.second == e){
                populate(res,t,sentinel);
                return res;
            }
            discard.insert(t.second);
            for(int k = 0; k < 8; k++){
                if(isSafe(t.second,X,Y,k,n,discard)){
                    Point p;
                    p.x = t.second.x+X[k];
                    p.y = t.second.y+Y[k];
                    q.push(make_pair(&t,p));
                }
            }
        }
        c++;
    }
    return c;
}

/* Not tested - giving set-Point related errors.
 * Note: This is similar to word ladder with 2-ended BFS.
 * Note: We could accomplish a traditional BFS with a queue like level order traversal. We could also optimize the neighbors by pruning neighbors farther from the target.
 * Note: If we need to retrace the path to get the min path, we can store <pair,pair> in the queue instead of just a pair/Point. 1st - parent, 2- child. Then, we backtrace and keep putting parents into the result.
 * Time complexity: O(n*n) since all slots could be positions.
 * Space complexity: O(n*n) since we might have to put everything in the queue.
 */
