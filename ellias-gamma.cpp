//EPI 5.9
string to_binary(const int &x) {
  string res;
  while(x) {
    res.insert(0, 1, x&1 + '0');
    x >> 1;
  }
  return res;
}

string encode(const vector<int> &A) {
  string res="";
  for(int i = 0; i < A.size(); i++) {
    string tmp = to_binary(A[i]);    
    tmp.insert(0,tmp.size()-1,'0');
    res+=tmp;
  }
  return res;
}

int to_int(const string &s) {
  int res = 0;
  for(const &c : s) {
    res = (res << 1) + c-'0';
  }
  return res;
}

vector<int> decode(const string &s) {
  vector<int> res;
  int idx = 0;
  while(idx < s.size()) {
    zero_idx = idx;
    while(zero_idx < s.size() && s[zero_idx] == '0')
      zero_idx++;
    int n = zero_idx - idx + 1;
    res.push_back(to_int(s.substr(zero_idx,n)));
    idx = zero_idx + n;
  }
  return res;
}
