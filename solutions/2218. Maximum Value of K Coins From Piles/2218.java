class Solution {
  public int maxValueOfCoins(List<List<Integer>> piles, int k) {
    // dp[i][k] := the maximum value of picking k coins from piles[i..n)
    dp = new Integer[piles.size()][k + 1];
    return maxValueOfCoins(piles, 0, k);
  }

  private Integer[][] dp;

  private int maxValueOfCoins(List<List<Integer>> piles, int i, int k) {
    if (i == piles.size() || k == 0)
      return 0;
    if (dp[i][k] != null)
      return dp[i][k];

    // Pick no coins from the current pile.
    int ans = maxValueOfCoins(piles, i + 1, k);
    int val = 0; // the coins picked from the current pile

    // Try to pick 1, 2, ..., k coins from the current pile.
    for (int j = 0; j < Math.min(piles.get(i).size(), k); ++j) {
      val += piles.get(i).get(j);
      ans = Math.max(ans, val + maxValueOfCoins(piles, i + 1, k - j - 1));
    }

    return dp[i][k] = ans;
  }
}
