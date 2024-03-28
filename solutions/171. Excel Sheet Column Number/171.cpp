class Solution {
 public:
  int titleToNumber(string s) {
    return accumulate(s.begin(), s.end(), 0,
                      [](int a, int b) { return a * 26 + (b - 'A' + 1); });
  }
};
