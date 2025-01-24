class Solution {
  public int maxValueOfCoins(List<List<Integer>> piles, int k) {
    Integer[][] mem = new Integer[piles.size()][k + 1];
    return maxValueOfCoins(piles, 0, k, mem);
  }

  // Returns the maximum value of picking k coins from piles[i..n)
  private int maxValueOfCoins(List<List<Integer>> piles, int i, int k, Integer[][] mem) {
    if (i == piles.size() || k == 0)
      return 0;
    if (mem[i][k] != null)
      return mem[i][k];

    // Pick no coins from the current pile.
    int res = maxValueOfCoins(piles, i + 1, k, mem);
    int val = 0; // the coins picked from the current pile

    // Try to pick 1, 2, ..., k coins from the current pile.
    for (int j = 0; j < Math.min(piles.get(i).size(), k); ++j) {
      val += piles.get(i).get(j);
      res = Math.max(res, val + maxValueOfCoins(piles, i + 1, k - j - 1, mem));
    }

    return mem[i][k] = res;
  }
}
