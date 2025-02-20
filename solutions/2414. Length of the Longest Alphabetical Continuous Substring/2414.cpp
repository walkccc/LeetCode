class Solution {
 public:
  int longestContinuousSubstring(string s) {
    int ans = 1;
    int runningLen = 1;

    for (int i = 1; i < s.length(); ++i)
      if (s[i] == s[i - 1] + 1)
        ans = max(ans, ++runningLen);
      else
        runningLen = 1;

    return ans;
  }
};
