class Solution {
  public int stoneGameVIII(int[] stones) {
    final int n = stones.length;
    int[] prefix = stones.clone();
    // dp[i] := max score diff the current player can get when the game starts
    // at i, i.e., stones[0..i] are merged whose value is prefix[i]
    int[] dp = new int[n];
    Arrays.fill(dp, Integer.MIN_VALUE);

    for (int i = 1; i < prefix.length; ++i)
      prefix[i] += prefix[i - 1];

    // must take all when there're only two stones left
    dp[n - 2] = prefix[n - 1];

    for (int i = n - 3; i >= 0; --i)
      dp[i] = Math.max(dp[i + 1], prefix[i + 1] - dp[i + 1]);

    return dp[0];
  }
}
