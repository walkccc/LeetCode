class Solution {
  public int numberWays(List<List<Integer>> hats) {
    final int kMod = 1_000_000_007;
    final int nHats = 40;
    final int nPeople = hats.size();
    final int nAssignments = 1 << nPeople;
    List<Integer>[] hatToPeople = new List[nHats + 1];
    // dp[i] := the number of ways to assign the hats so far to people, where i
    // is the bitmask of the current assignment
    int[] dp = new int[nAssignments];
    dp[0] = 1;

    for (int i = 1; i <= nHats; ++i)
      hatToPeople[i] = new ArrayList<>();

    for (int i = 0; i < nPeople; ++i)
      for (final int hat : hats.get(i))
        hatToPeople[hat].add(i);

    for (int h = 1; h <= nHats; ++h)
      for (int j = nAssignments - 1; j >= 0; --j)
        for (final int p : hatToPeople[h])
          if ((j & 1 << p) > 0) {
            dp[j] += dp[j ^ 1 << p];
            dp[j] %= kMod;
          }

    return dp[nAssignments - 1];
  }
}
