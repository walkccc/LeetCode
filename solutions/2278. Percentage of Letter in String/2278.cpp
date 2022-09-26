class Solution {
 public:
  int percentageLetter(string s, char letter) {
    return 100 * count(begin(s), end(s), letter) / s.length();
  }
};
