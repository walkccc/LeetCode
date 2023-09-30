class Solution {
 public:
  bool makePalindrome(string s) {
    int change = 0;
    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
      if (s[l] != s[r] && ++change > 2)
        return false;
      ++l;
      --r;
    }

    return true;
  }
};
