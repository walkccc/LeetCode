class Solution {
  public int numberWays(List<List<Integer>> hats) {
    final int nHats = 40;
    final int nPeople = hats.size();
    hatToPeople = new List[nHats + 1];
    // dp[i][j] := # of ways to assign hats 1, 2, ..., i to people in mask j
    dp = new Integer[nHats + 1][1 << nPeople];

    for (int i = 1; i <= nHats; ++i)
      hatToPeople[i] = new ArrayList<>();

    for (int i = 0; i < nPeople; ++i)
      for (final int hat : hats.get(i))
        hatToPeople[hat].add(i);

    return ways(hats, 0, 1);
  }

  private static final int kMod = 1_000_000_007;
  private List<Integer>[] hatToPeople;
  private Integer[][] dp;

  private int ways(List<List<Integer>> hats, int assignment, int h) {
    // all people are assigned
    if (assignment == (1 << hats.size()) - 1)
      return 1;
    if (h > 40)
      return 0;
    if (dp[h][assignment] != null)
      return dp[h][assignment];

    // don't wear hat h
    int ans = ways(hats, assignment, h + 1);

    for (final int p : hatToPeople[h]) {
      // person p was assigned hat h before
      if ((assignment & 1 << p) > 0)
        continue;

      // assigned hat h to person p
      ans += ways(hats, assignment | 1 << p, h + 1);
      ans %= kMod;
    }

    return dp[h][assignment] = ans;
  }
}
