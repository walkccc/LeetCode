class Solution {
  public int longestSemiRepetitiveSubstring(String s) {
    int ans = 1;
    int prevStart = 0;
    int start = 0;

    for (int i = 1; i < s.length(); ++i) {
      if (s.charAt(i) == s.charAt(i - 1)) {
        if (prevStart > 0)
          start = prevStart;
        prevStart = i;
      }
      ans = Math.max(ans, i - start + 1);
    }

    return ans;
  }
}
