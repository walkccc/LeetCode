class Solution {
  public int minDeletionSize(String[] A) {
    final int n = A[0].length();
    // dp[i] := LIS ending at A[*][i]
    int[] dp = new int[n];
    Arrays.fill(dp, 1);

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (isSorted(A, j, i))
          dp[i] = Math.max(dp[i], dp[j] + 1);

    return n - Arrays.stream(dp).max().getAsInt();
  }

  private boolean isSorted(String[] A, int j, int i) {
    for (final String a : A)
      if (a.charAt(j) > a.charAt(i))
        return false;
    return true;
  }
}
