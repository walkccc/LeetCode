class Solution {
  public int maxSumTwoNoOverlap(int[] A, int L, int M) {
    return Math.max(helper(A, L, M), helper(A, M, L));
  }

  private int helper(int[] A, int l, int r) {
    final int n = A.length;

    int[] left = new int[n];
    int sum = 0;

    for (int i = 0; i < n; ++i) {
      sum += A[i];
      if (i >= l)
        sum -= A[i - l];
      if (i >= l - 1)
        left[i] = i > 0 ? Math.max(left[i - 1], sum) : sum;
    }

    int[] right = new int[n];
    sum = 0;

    for (int i = n - 1; i >= 0; --i) {
      sum += A[i];
      if (i <= n - r - 1)
        sum -= A[i + r];
      if (i <= n - r)
        right[i] = i < n - 1 ? Math.max(right[i + 1], sum) : sum;
    }

    int ans = 0;

    for (int i = 0; i < n - 1; ++i)
      ans = Math.max(ans, left[i] + right[i + 1]);

    return ans;
  }
}
