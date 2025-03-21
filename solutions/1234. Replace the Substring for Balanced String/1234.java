class Solution {
  public int balancedString(String s) {
    final int n = s.length();
    final int k = n / 4;
    int ans = n;
    int[] count = new int[128];

    for (final char c : s.toCharArray())
      ++count[c];

    for (int i = 0, j = 0; i < n; ++i) {
      --count[s.charAt(i)];
      while (j < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
        ans = Math.min(ans, i - j + 1);
        ++count[s.charAt(j)];
        ++j;
      }
    }

    return ans;
  }
}
