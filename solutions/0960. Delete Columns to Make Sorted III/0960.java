class Solution {
  public int minDeletionSize(String[] A) {
    final int N = A[0].length();

    // dp[i] := LIS ending at A[*][i]
    int[] dp = new int[N];
    Arrays.fill(dp, 1);

    for (int i = 1; i < N; ++i)
      for (int j = 0; j < i; ++j)
        if (isSorted(A, j, i))
          dp[i] = Math.max(dp[i], dp[j] + 1);

    return N - Arrays.stream(dp).max().getAsInt();
  }

  private boolean isSorted(String[] A, int j, int i) {
    for (final String a : A)
      if (a.charAt(j) > a.charAt(i))
        return false;
    return true;
  }
}
