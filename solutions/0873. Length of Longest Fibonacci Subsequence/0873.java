class Solution {
  public int lenLongestFibSubseq(int[] A) {
    final int n = A.length;
    int ans = 0;
    int[][] dp = new int[n][n];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, 2));
    Map<Integer, Integer> numToIndex = new HashMap<>();

    for (int i = 0; i < n; ++i)
      numToIndex.put(A[i], i);

    for (int j = 0; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        final int ai = A[k] - A[j];
        if (ai < A[j] && numToIndex.containsKey(ai)) {
          final int i = numToIndex.get(ai);
          dp[j][k] = dp[i][j] + 1;
          ans = Math.max(ans, dp[j][k]);
        }
      }

    return ans;
  }
}
