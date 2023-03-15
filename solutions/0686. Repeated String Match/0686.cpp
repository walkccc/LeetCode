class Solution {
 public:
  int repeatedStringMatch(string a, string b) {
    const int n = ceil((double)b.length() / a.length());
    string s;

    for (int i = 0; i < n; ++i)
      s += a;

    if (s.find(b) != string::npos)
      return n;
    if ((s + a).find(b) != string::npos)
      return n + 1;
    return -1;
  }
};
