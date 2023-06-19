class Solution {
 public:
  int percentageLetter(string s, char letter) {
    return 100 * count(s.begin(), s.end(), letter) / s.length();
  }
};
