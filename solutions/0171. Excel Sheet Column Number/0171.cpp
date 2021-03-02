class Solution {
 public:
  int titleToNumber(string s) {
    return accumulate(begin(s), end(s), 0,
                      [](int a, int b) { return a * 26 + (b - 'A' + 1); });
  }
};
