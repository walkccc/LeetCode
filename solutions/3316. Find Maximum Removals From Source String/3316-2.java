class Solution {
  public int maxRemovals(String source, String pattern, int[] targetIndices) {
    final int m = source.length();
    final int n = pattern.length();
    Set<Integer> target = Arrays.stream(targetIndices).boxed().collect(Collectors.toSet());
    // dp[i][j] := the maximum number of operations that can be performed for
    // source[i..m) and pattern[j..n)
    int[][] dp = new int[m + 1][n + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MIN_VALUE));
    dp[m][n] = 0;

    for (int i = m - 1; i >= 0; --i) {
      dp[i][n] = (target.contains(i) ? 1 : 0) + dp[i + 1][n];
      for (int j = n - 1; j >= 0; --j) {
        final int pick =
            source.charAt(i) == pattern.charAt(j) ? dp[i + 1][j + 1] : Integer.MIN_VALUE;
        final int skip = (target.contains(i) ? 1 : 0) + dp[i + 1][j];
        dp[i][j] = Math.max(pick, skip);
      }
    }

    return dp[0][0] == Integer.MIN_VALUE ? 0 : dp[0][0];
  }
}
