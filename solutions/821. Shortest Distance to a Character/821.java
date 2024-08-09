class Solution {
  public int[] shortestToChar(String s, char c) {
    final int n = s.length();
    int[] ans = new int[n];
    int prev = -n;

    for (int i = 0; i < n; ++i) {
      if (s[i] == c)
        prev = i;
      ans[i] = i - prev;
    }

    for (int i = prev - 1; i >= 0; --i) {
      if (s[i] == c)
        prev = i;
      ans[i] = Math.min(ans[i], prev - i);
    }

    return ans;
  }
}
