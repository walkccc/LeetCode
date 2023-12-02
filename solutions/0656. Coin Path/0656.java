class Solution {
  public List<Integer> cheapestJump(int[] coins, int maxJump) {
    if (coins[coins.length - 1] == -1)
      return new ArrayList<>();

    final int n = coins.length;
    int[] next = new int[n];
    Arrays.fill(next, -1);

    // dp[i] := the minimum cost to jump from i to n - 1
    dp = new int[n];
    Arrays.fill(dp, Integer.MAX_VALUE);
    cheapestJump(coins, maxJump, 0, next);

    if (dp[0] == Integer.MAX_VALUE)
      return new ArrayList<>();
    return constructPath(next, 0);
  }

  private int[] dp;

  private int cheapestJump(int[] coins, int maxJump, int i, int[] next) {
    if (i == coins.length - 1)
      return dp[i] = coins[i];
    if (dp[i] < Integer.MAX_VALUE)
      return dp[i];
    if (coins[i] == -1)
      return Integer.MAX_VALUE;

    for (int j = i + 1; j < Math.min(i + maxJump + 1, coins.length); ++j) {
      final int res = cheapestJump(coins, maxJump, j, next);
      if (res == Integer.MAX_VALUE)
        continue;
      final int cost = coins[i] + res;
      if (cost < dp[i]) {
        dp[i] = cost;
        next[i] = j;
      }
    }

    return dp[i];
  }

  private List<Integer> constructPath(int[] next, int i) {
    List<Integer> ans = new ArrayList<>();
    while (i != -1) {
      ans.add(i + 1); // 1-indexed
      i = next[i];
    }
    return ans;
  }
}
