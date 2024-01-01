class Solution {
 public:
  int removePalindromeSub(string s) {
    return equal(s.begin(), s.end(), s.rbegin()) ? 1 : 2;
  }
};
