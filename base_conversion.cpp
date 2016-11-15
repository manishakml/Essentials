//EPI 5.7
string base_conversion(const string &s, const int &b1, const int &b2) {
  string res;
  int x;
  bool neg = s[0] == '-'? true: false;
  
  for(int i = neg; i < s.size(); i++) {
    x = x*b1;
    if(is_digit(s[i])) {
      x += s[i] -'0';
    } else {
      x += s[i]-'A'*10;
    }
  }
  
  while(x) {
    if((x%b2) <= 9 && (x%b2) >=0)
       res.push_back(x%b2 + '0');
    else
      res.push_back('A' + (x%b2)-10);
    x /= b2;
  }
  
  if(res.empty())
    res.push_back('0');
  
  if(neg)
    res.push_back('-');
  reverse(res.begin(),res.end());
  return res;
}
