class Solution {
  public int maxRemovals(String source, String pattern, int[] targetIndices) {
    final int m = source.length();
    final int n = pattern.length();
    Set<Integer> target = Arrays.stream(targetIndices).boxed().collect(Collectors.toSet());
    // dp[j] := the maximum number of operations that can be performed for
    // source so far and pattern[j..n)
    int[] dp = new int[n + 1];
    Arrays.fill(dp, Integer.MIN_VALUE);
    dp[n] = 0;

    for (int i = m - 1; i >= 0; --i) {
      int[] newDp = dp.clone();
      newDp[n] = (target.contains(i) ? 1 : 0) + dp[n];
      for (int j = n - 1; j >= 0; --j) {
        final int pick = source.charAt(i) == pattern.charAt(j) ? dp[j + 1] : Integer.MIN_VALUE;
        final int skip = (target.contains(i) ? 1 : 0) + dp[j];
        newDp[j] = Math.max(pick, skip);
      }
      dp = newDp;
    }

    return dp[0] == Integer.MIN_VALUE ? 0 : dp[0];
  }
}
