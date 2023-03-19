class Solution {
  public List<Integer> cheapestJump(int[] coins, int maxJump) {
    if (coins[coins.length - 1] == -1)
      return new ArrayList<>();

    final int n = coins.length;
    // dp[i] := min cost to jump from i to n - 1
    int[] dp = new int[n];
    int[] next = new int[n];

    Arrays.fill(dp, Integer.MAX_VALUE);
    Arrays.fill(next, -1);

    dp[n - 1] = coins[n - 1];

    for (int i = n - 2; i >= 0; --i) {
      if (coins[i] == -1)
        continue;
      for (int j = i + 1; j < Math.min(i + maxJump + 1, n); ++j) {
        if (dp[j] == Integer.MAX_VALUE)
          continue;
        final int cost = coins[i] + dp[j];
        if (cost < dp[i]) {
          dp[i] = cost;
          next[i] = j;
        }
      }
    }

    if (dp[0] == Integer.MAX_VALUE)
      return new ArrayList<>();
    return constructPath(next, 0);
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
