class Solution {
  public int longestContinuousSubstring(String s) {
    int ans = 1;
    int runningLen = 1;

    for (int i = 1; i < s.length(); ++i)
      if (s.charAt(i) == s.charAt(i - 1) + 1)
        ans = Math.max(ans, ++runningLen);
      else
        runningLen = 1;

    return ans;
  }
}
