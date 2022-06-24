class Solution {
  public long maxProduct(String s) {
    final int n = s.length();
    long ans = 1;
    // l[i] := max length of palindromes in s[0..i)
    int[] l = manacher(s, n);
    // r[i] := max length of palindromes in s[i..n)
    int[] r = manacher(new StringBuilder(s).reverse().toString(), n);

    reverse(r, 0, n - 1);

    for (int i = 0; i + 1 < n; ++i)
      ans = Math.max(ans, (long) l[i] * r[i + 1]);

    return ans;
  }

  private int[] manacher(final String s, int n) {
    int[] maxExtends = new int[n];
    int[] l2r = new int[n];
    Arrays.fill(l2r, 1);
    int center = 0;

    for (int i = 0; i < n; ++i) {
      final int r = center + maxExtends[center] - 1;
      final int mirrorIndex = center - (i - center);
      int extend = i > r ? 1 : Math.min(maxExtends[mirrorIndex], r - i + 1);
      while (i - extend >= 0 && i + extend < n && s.charAt(i - extend) == s.charAt(i + extend)) {
        l2r[i + extend] = 2 * extend + 1;
        ++extend;
      }
      maxExtends[i] = extend;
      if (i + maxExtends[i] >= r)
        center = i;
    }

    for (int i = 1; i < n; ++i)
      l2r[i] = Math.max(l2r[i], l2r[i - 1]);

    return l2r;
  }

  private void reverse(int[] A, int l, int r) {
    while (l < r)
      swap(A, l++, r--);
  }

  private void swap(int[] A, int i, int j) {
    final int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
}
