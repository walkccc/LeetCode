class Solution {
  public int[] kthSmallestPrimeFraction(int[] A, int K) {
    final int n = A.length;
    double l = 0.0;
    double r = 1.0;

    while (l < r) {
      final double m = (l + r) / 2.0;
      int fractionsNoGreaterThanM = 0;
      int p = 0;
      int q = 1;

      // for each index i, find the first index j s.t. A[i] / A[j] <= m,
      // so fractionsNoGreaterThanM for index i will be n - j
      for (int i = 0, j = 1; i < n; ++i) {
        while (j < n && A[i] > m * A[j])
          ++j;
        if (j == n)
          break;
        fractionsNoGreaterThanM += n - j;
        if (p * A[j] < q * A[i]) {
          p = A[i];
          q = A[j];
        }
      }

      if (fractionsNoGreaterThanM == K)
        return new int[] {p, q};
      if (fractionsNoGreaterThanM > K)
        r = m;
      else
        l = m;
    }

    throw new IllegalArgumentException();
  }
}
