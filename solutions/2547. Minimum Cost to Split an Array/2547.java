class Solution {
  public int minCost(int[] nums, int k) {
    final int kMax = 1001;
    final int n = nums.length;
    // trimmedLength[i][j] := trimmed(nums[i..j]).length
    int[][] trimmedLength = new int[n][n];
    // dp[i] := the minimum cost to split nums[i..n)
    int[] dp = new int[n + 1];
    Arrays.fill(dp, Integer.MAX_VALUE / 2);

    for (int i = 0; i < n; ++i) {
      int length = 0;
      int[] count = new int[kMax];
      for (int j = i; j < n; ++j) {
        if (++count[nums[j]] == 2)
          length += 2;
        else if (count[nums[j]] > 2)
          ++length;
        trimmedLength[i][j] = length;
      }
    }

    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int j = i; j < n; ++j)
        dp[i] = Math.min(dp[i], k + trimmedLength[i][j] + dp[j + 1]);

    return dp[0];
  }
}
