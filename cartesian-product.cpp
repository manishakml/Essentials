/* Given a list of lists, output a list of lists with each list containing one element from each of the lists. The result should contain all combinations.
 * Eg. {{a,b,c},{d},{e,f}}, Output: {{a,d,e},{a,d,f},{b,d,e},{b,d,f},{c,d,e},{c,d,f}}
 */
 
 #include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<char>> &A, vector<vector<char>> &res, vector<char> &ans, int idx){
    if(idx == A.size()){
      res.push_back(ans);
    } else {
      for(int i = 0; i < A[idx].size(); i++){
        ans.push_back(A[idx][i]);
        helper(A, res, ans, idx + 1);
        ans.pop_back();
      }
    }
 }


vector<vector<char>> cartesian(vector<vector<char>> &A){
  vector<vector<char>> res;
  vector<char> ans;
  helper(A,res,ans,0);
  return res;
 }

int main(){
        vector<vector<char>> A = {{'a','b','c'},
                                  {'d'},
                                  {'e','f'}};
        vector<vector<char>> res = cartesian(A);
        for(auto i : res){
                for(auto j : i){
                        cout << j;
                }
                cout << endl;
        }
        return 1;
}

 
 /* Not tested thoroughly.
  * Time complexity: Exponential
  * Space complexity: O(n) where n is the number of lists
  */
