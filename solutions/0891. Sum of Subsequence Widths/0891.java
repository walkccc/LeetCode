class Solution {
  public int sumSubseqWidths(int[] A) {
    final int n = A.length;
    final int kMod = (int) 1e9 + 7;

    long ans = 0;
    long exp = 1;

    Arrays.sort(A);

    for (int i = 0; i < n; ++i, exp = exp * 2 % kMod)
      ans = (ans + A[i] * exp - A[n - i - 1] * exp) % kMod;

    return (int) ans;
  }
}
