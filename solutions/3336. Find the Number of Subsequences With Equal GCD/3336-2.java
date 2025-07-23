class Solution {
  public int subsequencePairCount(int[] nums) {
    final int MOD = 1_000_000_007;
    final int n = nums.length;
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    // dp[i][x][y] := number of disjoint pairs `seq1` and `seq2` of
    // nums[0..i - 1], where GCD(seq1) == x and GCD(seq2) == y
    int[][][] dp = new int[n + 1][maxNum + 1][maxNum + 1];
    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i)
      for (int x = 0; x <= maxNum; ++x)
        for (int y = 0; y <= maxNum; ++y) {
          // 1. Skip nums[i].
          dp[i + 1][x][y] += dp[i][x][y];
          dp[i + 1][x][y] %= MOD;
          // 2. Pick nums[i] in the first subsequence.
          final int newX = gcd(x, nums[i]);
          dp[i + 1][newX][y] += dp[i][x][y];
          dp[i + 1][newX][y] %= MOD;
          // 3. Pick nums[i] in the second subsequence.
          final int newY = gcd(y, nums[i]);
          dp[i + 1][x][newY] += dp[i][x][y];
          dp[i + 1][x][newY] %= MOD;
        }

    int ans = 0;
    for (int g = 1; g <= maxNum; ++g) {
      ans += dp[n][g][g];
      ans %= MOD;
    }
    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
