class Solution {
  public long sumScores(String s) {
    final int n = s.length();
    int[] z = new int[n];
    // [l, r] := indices of the rightmost segment match
    int l = 0;
    int r = 0;

    for (int i = 1; i < n; ++i) {
      if (i <= r)
        z[i] = Math.min(r - i + 1, z[i - l]);
      while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i]))
        ++z[i];
      if (i + z[i] - 1 > r) {
        l = i;
        r = i + z[i] - 1;
      }
    }

    return Arrays.stream(z).sum().getAsInt() + n;
  }
}
