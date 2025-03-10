class Solution {
 public:
  int longestCommonPrefix(string s, string t) {
    int i = 0;  // s's index
    int j = 0;  // t's index
    bool canSkip = true;

    while (i < s.length() && j < t.length())
      if (s[i] == t[j]) {
        ++i;
        ++j;
      } else if (canSkip) {
        ++i;
        canSkip = false;
      } else {
        return j;
      }

    return j;
  }
};
