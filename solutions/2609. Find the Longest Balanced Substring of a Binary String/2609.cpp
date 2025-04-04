class Solution {
 public:
  int findTheLongestBalancedSubstring(string s) {
    int ans = 0;

    for (int i = 0; i < s.length();) {
      int zeros = 0;
      int ones = 0;
      while (i < s.length() && s[i] == '0') {
        ++zeros;
        ++i;
      }
      while (i < s.length() && s[i] == '1') {
        ++ones;
        ++i;
      }
      ans = max(ans, min(zeros, ones));
    }

    return ans * 2;
  }
};
