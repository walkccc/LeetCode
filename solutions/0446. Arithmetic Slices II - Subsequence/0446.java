class Solution {
  public int numberOfArithmeticSlices(int[] A) {
    final int n = A.length;

    int ans = 0;
    // dp[i][j] := # of subseqs end w/ A[j] A[i]
    int[][] dp = new int[n][n];
    Map<Long, List<Integer>> numToIndices = new HashMap<>();

    for (int i = 0; i < n; ++i) {
      numToIndices.putIfAbsent((long) A[i], new ArrayList<>());
      numToIndices.get((long) A[i]).add(i);
    }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        final long target = (long) A[j] * 2 - A[i];
        if (numToIndices.containsKey(target))
          for (final int k : numToIndices.get(target))
            if (k < j)
              dp[i][j] += (dp[j][k] + 1);
        ans += dp[i][j];
      }

    return ans;
  }
}
