/* Given a file (String) and k, split the string into k-length pages. If a string does not fit completely in a page, do not include it in the page.
 * Assume the file is well formed with no multi spaces. If there are multispaces, it is ok to compress them to one space.
 */
 
 #include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

vector<string> paginate(string s, int len) {
    vector<string> res;
    istringstream in(s);
    string ans = "";
    string val;
    while(in >> val) {
        if(val.length() > len) {
            res.clear();
            break;
        }
        if(ans.length() + val.length() == len || ans.length() + val.length() + 1 > len) {
            if(ans.length() + val.length() == len) {
                ans += val;
                continue;
            }
            res.push_back(ans);
            ans.clear();
        }
        ans += val + " ";
    }
    return res;
}

int main(){
    string s = "asdas asdasd ccddfsdf asdaerdsb          a\
                asdasewe daeweqweda sdawew asdasdweqe weqwe  weqwe\
                asdawew       ewewqeq";
    int n = 10;
    vector<string> res = paginate(s,n);

    for(int i = 0; i < res.size(); i++){
        cout << '#' << res[i] << "#\n";
    }
    return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

