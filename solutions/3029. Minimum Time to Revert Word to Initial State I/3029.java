class Solution {
  // Same as 3029. Minimum Time to Revert Word to Initial State I
  public int minimumTimeToInitialState(String word, int k) {
    final int n = word.length();
    final int maxOps = (n - 1) / k + 1;
    final int[] z = zFunction(word);
    for (int ans = 1; ans < maxOps; ++ans)
      if (z[ans * k] >= n - ans * k)
        return ans;
    return maxOps;
  }

  // Returns the z array, where z[i] is the length of the longest prefix of
  // s[i..n) which is also a prefix of s.
  //
  // https://cp-algorithms.com/string/z-function.html#implementation
  private int[] zFunction(final String s) {
    final int n = s.length();
    int[] z = new int[n];
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
      if (i < r)
        z[i] = Math.min(r - i, z[i - l]);
      while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i]))
        ++z[i];
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }
    return z;
  }
}
