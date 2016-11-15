//EPI 5.6
string int_to_string(int x) {
  bool neg = (x < 0)? true:false;
  x = abs(x);
  string res;
  while(x) {
    res.push_back(x%10 + '0');
    x /= 10;
  }
  if(res.empty()) {
    res.push_back('0');
    return res;
  }
  if(neg) {
    res.push_back('-');
  }
  reverse(res.begin(), res.end());
  return res;
}

int string_to_int(string s) {
  bool neg = (s[i] == '-')? true:false;
  int res = 0;
  for(int i = neg; i < s.size(); i++) {
    if(is_digit(s[i]) {
      res = res*10 + s[i]-'0';
    } else {
      throw invalid_argument("illegal input");
    }
  }
  if(neg) res = - res;
  return res;
}
