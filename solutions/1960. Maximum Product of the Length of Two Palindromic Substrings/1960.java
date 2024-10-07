class Solution {
  public long maxProduct(String s) {
    final int n = s.length();
    long ans = 1;
    // maxLeft[i] := the maximum odd length of palindromes in s[0..i]
    int[] maxLeft = manacher(s, n);
    // maxRight[i] := the maximum odd length of palindromes in s[i..n - 1]
    int[] maxRight = manacher(new StringBuilder(s).reverse().toString(), n);

    reverse(maxRight, 0, n - 1);

    for (int i = 1; i < n; ++i)
      ans = Math.max(ans, (long) maxLeft[i - 1] * maxRight[i]);

    return ans;
  }

  private int[] manacher(final String s, int n) {
    int[] maxExtends = new int[n];
    int[] leftToRight = new int[n];
    Arrays.fill(leftToRight, 1);
    int center = 0;

    for (int i = 0; i < n; ++i) {
      final int r = center + maxExtends[center] - 1;
      final int mirrorIndex = center - (i - center);
      int extend = i > r ? 1 : Math.min(maxExtends[mirrorIndex], r - i + 1);
      while (i - extend >= 0 && i + extend < n && s.charAt(i - extend) == s.charAt(i + extend)) {
        leftToRight[i + extend] = 2 * extend + 1;
        ++extend;
      }
      maxExtends[i] = extend;
      if (i + maxExtends[i] >= r)
        center = i;
    }

    for (int i = 1; i < n; ++i)
      leftToRight[i] = Math.max(leftToRight[i], leftToRight[i - 1]);

    return leftToRight;
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
