class Solution {
 public:
  int longestSemiRepetitiveSubstring(string s) {
    int ans = 1;
    int prevStart = 0;
    int start = 0;

    for (int i = 1; i < s.length(); ++i) {
      if (s[i] == s[i - 1]) {
        if (prevStart > 0)
          start = prevStart;
        prevStart = i;
      }
      ans = max(ans, i - start + 1);
    }

    return ans;
  }
};
