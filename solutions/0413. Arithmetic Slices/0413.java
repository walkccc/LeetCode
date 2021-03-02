class Solution {
  public int numberOfArithmeticSlices(int[] A) {
    final int n = A.length;
    if (n < 3)
      return 0;

    int[] dp = new int[n]; // dp[i] := # of arithmetic slices ends at A[i]

    for (int i = 2; i < n; ++i)
      if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
        dp[i] += dp[i - 1] + 1;

    return Arrays.stream(dp).sum();
  }
}
