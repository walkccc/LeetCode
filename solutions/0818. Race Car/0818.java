class Solution {
  public int racecar(int target) {
    dp = new int[target + 1];
    Arrays.fill(dp, 1, dp.length, -1);
    return rc(target);
  }

  private int[] dp;

  private int rc(int i) {
    if (dp[i] >= 0)
      return dp[i];

    int ans = Integer.MAX_VALUE;
    int x = 1;            // xA := (2^x - 1) unit distance
    int j = (1 << x) - 1; // j = 2^x - 1, k = 2^y - 1

    // (xA + 1R) + (yA + 1R) + rc(i - (j - k))
    for (; j < i; j = (1 << ++x) - 1)
      for (int y = 0, k = 0; k < j; k = (1 << ++y) - 1)
        ans = Math.min(ans, (x + 1) + (y + 1) + rc(i - (j - k)));

    // xA || (xA + 1R) + rc(j - i)
    ans = Math.min(ans, i == j ? x : x + 1 + rc(j - i));
    return dp[i] = ans;
  }
}
