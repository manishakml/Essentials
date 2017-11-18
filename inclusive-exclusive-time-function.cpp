/* Given a list of log messages - each message containing name of the function, an indicator to say whether it is the start time or end time and a timestamp, find the inclusive and exclusive time of a given function.
 * For instance, "a,start,100" and "b,start,200", "b,end,300" and "a,end,400".
 * To find out inclusive time for a: 400-100 = 300. Exclusive time = (400-100)-(300-200) = 200.
 * b is the child function of a in this case.
 * All messages are ordered by timestamp and we can assume that there are no out-of-order messages.
 */
 
 #include<iostream>
#include<stack>
#include<vector>
#include<utility>
using namespace std;

typedef struct packet {
    string name;
    bool indicator;
    int time;
}pkt;

//Approach 1 using stack
pair<int,int> fntm(const string &fn, const vector<pkt> &A) {
    pair<int,int> res;
    stack<pkt> s;
    int f_start = -1, f_end = -1, excl = 0;

    for(int i = 0; i < A.size(); i++) {
        pkt a = A[i];
     /* If each log is in the form of string:
     string t = A[i];
        istringstream in(t);
        string val;
        vector<string> B;
        while(getline(in,val,',')) {
            B.push_back(val);
        }
        pkt a;
        a.name = B[0];
        a.indicator = B[1] == "start"?1:0;
        a.time = stoi(B[2]);
        */
        if(a.indicator && (a.name==fn || (!s.empty() && s.top().name==fn))) {
            s.push(a);
            if(a.name==fn) {
                f_start = a.time;
            }
        }
        if(!a.indicator && (a.name==fn || (!s.empty() && s.top().name==a.name))){
            if(a.name==fn) {
                f_end = a.time;
            } else {
                excl += a.time - s.top().time;
            }
            s.pop();
        }
    }
    res.first = f_end - f_start;
    res.second = res.first - excl;
    return res;
}

// Approach 2 without stack
pair<int,int> fntm(const string &fn, const vector<string> &A) {
    pair<int,int> res;
    int f_start = -1, f_end = -1, excl = 0;
    bool parent_seen = false, child_seen = false;
    pkt child_pkt;
    for(int i = 0; i < A.size(); i++) {
        string t = A[i];
        istringstream in(t);
        string val;
        vector<string> B;
        while(getline(in,val,',')) {
            B.push_back(val);
        }
        pkt a;
        a.name = B[0];
        a.indicator = B[1] == "start"?1:0;
        a.time = stoi(B[2]);

        if(a.indicator && (a.name==fn || (parent_seen && !child_seen))) {
            if(a.name==fn) {
                parent_seen = true;
                f_start = a.time;
            } else {
                child_seen = true;
                child_pkt = a;
            }
        }
        if(!a.indicator && (a.name==fn || a.name == child_pkt.name)){
            if(a.name==fn) {
                f_end = a.time;
            } else {
                excl += a.time - child_pkt.time;
                child_seen = false;
            }
        }
    }
    res.first = f_end - f_start;
    res.second = res.first - excl;
    return res;
}

int main() {
    int n;
    pkt p;
    vector<pkt> A;
    cout << "Enter n:";
    cin >> n;
    while(n--) {
        cout << "\nEnter pkt details:";
        cin >> p.name >> p.indicator >> p.time;
        A.push_back(p);
    }

    pair<int,int> res = fntm("abc",A);
    cout << endl << res.first << " " << res.second;
    return 1;
}

/* Not tested thoroughly.
 * Note: We should only bother about the immediate children of the function in question. Deeper nestings can be ignored.
 * Note 2: Since only 2 layers are needed, stack is not needed - approach 2
 * Time complexity: O(n) where there are n log messages.
 * Space complexity: O(1) since we store only 'start' of only 1 child at a time (approach 1). O(1) for approach 2.
 */
