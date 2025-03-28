class Solution {
 public:
  string removeTrailingZeros(string num) {
    return regex_replace(num, regex("0+$"), "");
  }
};
