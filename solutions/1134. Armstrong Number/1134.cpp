class Solution {
 public:
  bool isArmstrong(int n) {
    const string s = to_string(n);
    const int k = s.length();
    for (const char c : s)
      n -= pow(c - '0', k);
    return n == 0;
  }
};
