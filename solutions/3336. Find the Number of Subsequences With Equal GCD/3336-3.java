class Solution {
  public int subsequencePairCount(int[] nums) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    // dp[x][y] := number of disjoint pairs `seq1` and `seq2` of
    // nums so far, where GCD(seq1) == x and GCD(seq2) == y
    int[][] dp = new int[maxNum + 1][maxNum + 1];
    dp[0][0] = 1;

    for (final int num : nums) {
      int[][] newDp = new int[maxNum + 1][maxNum + 1];
      for (int x = 0; x <= maxNum; ++x)
        for (int y = 0; y <= maxNum; ++y) {
          // 1. Skip `num`.
          newDp[x][y] += dp[x][y];
          newDp[x][y] %= kMod;
          // 2. Pick `num` in the first subsequence.
          final int newX = gcd(x, num);
          newDp[newX][y] += dp[x][y];
          newDp[newX][y] %= kMod;
          // 3. Pick `num` in the second subsequence.
          final int newY = gcd(y, num);
          newDp[x][newY] += dp[x][y];
          newDp[x][newY] %= kMod;
        }
      dp = newDp;
    }

    int ans = 0;
    for (int g = 1; g <= maxNum; ++g) {
      ans += dp[g][g];
      ans %= kMod;
    }
    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
