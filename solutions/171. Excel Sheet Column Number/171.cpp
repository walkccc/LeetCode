class Solution {
 public:
  int titleToNumber(string columnTitle) {
    return accumulate(
        columnTitle.begin(), columnTitle.end(), 0,
        [](int subtotal, char c) { return subtotal * 26 + (c - 'A' + 1); });
  }
};
