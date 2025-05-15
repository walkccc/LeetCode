class Solution {
  public int lastStoneWeightII(int[] stones) {
    final int sum = Arrays.stream(stones).sum();
    boolean[] dp = new boolean[sum + 1];
    dp[0] = true;
    int s = 0;

    for (int stone : stones)
      for (int w = sum / 2; w > 0; --w) {
        if (w >= stone)
          dp[w] = dp[w] || dp[w - stone];
        if (dp[w])
          s = Math.max(s, w);
      }

    return sum - 2 * s;
  }
}
