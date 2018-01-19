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


//approach without stack

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

struct pkt{
        string fn;
        bool start;
        long time;
};

pkt parse_string(string s){
        istringstream in(s);
        string val;
        pkt res;

        getline(in,val,',');
        res.fn = val;
        getline(in,val,',');
        res.start = val == "START"?1:0;
        getline(in,val,',');
        res.time = stol(val);

        return res;
}

pair<long,long> fn_time(vector<string> &A, string fn){
        pair<long,long> res;
        int n = A.size();
        if(n == 0){
                return res;
        }
        long incl_time = 0, excl_time = 0, child_time = 0;
        pkt p_pkt, c_pkt;
        bool p_seen, c_seen;

        for(int i = 0; i < A.size(); i++){
                pkt p = parse_string(A[i]);
                if(p.fn == fn){
                        if(p.start){
                                p_pkt = p;
                                p_seen = true;
                        } else {
                                p_seen = false;
                                incl_time += p.time - p_pkt.time;
                        }
                } else if(p_seen){
                        if(p.start && !c_seen){
                                c_pkt = p;
                                c_seen = true;
                        } else if(p.fn == c_pkt.fn){
                                child_time += p.time - c_pkt.time;
                                c_seen = false;
                        }
                 }
        }
        return make_pair(incl_time, incl_time - child_time);
}

int main(){
        string in;
        vector<string> A;
        int n;
        cout << "Enter n:";
        cin >> n;
        for(int i = 0; i < n; i++){
                cout << "\nEnter string:";
                cin >> in;
                A.push_back(in);
        }
        cout << "\nEnter target:";
        cin >> in;
        pair<long,long> p = fn_time(A,in);
        cout << p.first << ' ' << p.second;
        return 1;
}


/* Not tested thoroughly.
 * Note: We should only bother about the immediate children of the function in question. Deeper nestings can be ignored.
 * Note 2: Since only 2 layers are needed, stack is not needed - approach 2
 * Time complexity: O(n) where there are n log messages.
 * Space complexity: O(1) since we store only 'start' of only 1 child at a time (approach 1). O(1) for approach 2.
 */
