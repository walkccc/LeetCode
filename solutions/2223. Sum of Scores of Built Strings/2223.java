class Solution {
  public long sumScores(String s) {
    final int n = s.length();
    // https://cp-algorithms.com/string/z-function.html#implementation
    int[] z = new int[n];
    // [l, r] := the indices of the rightmost segment match
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

    return Arrays.stream(z).asLongStream().sum() + n;
  }
}
