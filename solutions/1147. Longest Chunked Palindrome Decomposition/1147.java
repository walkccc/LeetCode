class Solution {
  public int longestDecomposition(String text) {
    final int n = text.length();

    int count = 0;
    int l = 0;

    for (int r = 1; 2 * r <= n; ++r)
      if (text.substring(n - r).startsWith(text.substring(l, r))) {
        count += 2;
        l = r;
      }

    return count + (2 * l < n ? 1 : 0);
  }
}
