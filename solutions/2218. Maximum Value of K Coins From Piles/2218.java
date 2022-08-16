class Solution {
  public int maxValueOfCoins(List<List<Integer>> piles, int k) {
    // dp[i][k] := max value of picking k coins from piles[i:]
    dp = new Integer[piles.size()][k + 1];
    return maxValueOfCoins(piles, 0, k);
  }

  private Integer[][] dp;

  private int maxValueOfCoins(List<List<Integer>> piles, int i, int k) {
    if (i == piles.size() || k == 0)
      return 0;
    if (dp[i][k] != null)
      return dp[i][k];

    int ans = maxValueOfCoins(piles, i + 1, k); // pick 0 coins from current pile
    int val = 0;                                // coins picked from current pile

    // try to pick 1, 2, ..., k coins from current pile
    for (int j = 0; j < Math.min(piles.get(i).size(), k); ++j) {
      val += piles.get(i).get(j);
      ans = Math.max(ans, val + maxValueOfCoins(piles, i + 1, k - j - 1));
    }

    return dp[i][k] = ans;
  }
}
