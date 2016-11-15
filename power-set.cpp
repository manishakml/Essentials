//EPI 5.5
void power_set(const vector<int> &S) {
  int n = S.size();
  int subnum = pow(2,n);
  vector<vector<int>> res;
  for (int i = 0; i < subnum; i++) {
    vector<int> ans;
    for(int j = 0; j < n; j++) {
      if(i & (1<<j)) {
        ans.push_back(S[j]); // OR cout << S[j] << ",";
      }
    }
    res.push_back(ans);    //OR cout << '\n';
    ans.clear();
  }
  return res;
}
