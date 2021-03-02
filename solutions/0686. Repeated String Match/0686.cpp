class Solution {
 public:
  int repeatedStringMatch(string A, string B) {
    const int n = ceil((double)B.length() / A.length());

    string s;
    for (int i = 0; i < n; ++i)
      s += A;

    if (s.find(B) != string::npos)
      return n;
    if ((s + A).find(B) != string::npos)
      return n + 1;
    return -1;
  }
};
