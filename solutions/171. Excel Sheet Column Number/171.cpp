class Solution {
 public:
  int titleToNumber(string columnTitle) {
    return accumulate(columnTitle.begin(), columnTitle.end(), 0,
                      [](int acc, char c) { return acc * 26 + (c - 'A' + 1); });
  }
};
