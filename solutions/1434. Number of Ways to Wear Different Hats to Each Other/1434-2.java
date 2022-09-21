class Solution {
  public int numberWays(List<List<Integer>> hats) {
    final int kMod = 1_000_000_007;
    final int nHats = 40;
    final int nPeople = hats.size();
    final int nAssignments = 1 << nPeople;
    List<Integer>[] hatToPeople = new List[nHats + 1];
    // dp[i][j] := # of ways to assign hats 1, 2, ..., i to people in mask j
    int[][] dp = new int[nHats + 1][nAssignments];
    dp[0][0] = 1;

    for (int i = 1; i <= nHats; ++i)
      hatToPeople[i] = new ArrayList<>();

    for (int i = 0; i < nPeople; ++i)
      for (final int hat : hats.get(i))
        hatToPeople[hat].add(i);

    for (int h = 1; h <= nHats; ++h)
      // for each assignment j of people
      for (int j = 0; j < nAssignments; ++j) {
        // we can cover the assignment j in 2 ways:
        // (1) by first h - 1 hats (i.e., w/o hat h)
        dp[h][j] += dp[h - 1][j];
        dp[h][j] %= kMod;
        for (final int p : hatToPeople[h])
          if ((j & 1 << p) > 0) {
            // (2) by first h - 1 hats assigned to people w/o person p and
            //     hat h assigned to person p
            dp[h][j] += dp[h - 1][j ^ 1 << p];
            dp[h][j] %= kMod;
          }
      }

    return dp[nHats][nAssignments - 1];
  }
}
