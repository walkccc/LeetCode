class Solution {
  public int numberOfPermutations(int n, int[][] requirements) {
    final int kMod = 1_000_000_007;
    final int kMaxInversions = 400;
    // dp[i][j] := the number of ways to arrange the first i numbers of the
    // permutation such that there are j inversions
    int[][] dp = new int[n + 1][kMaxInversions + 1];
    int[] endToCnt = new int[n + 1];
    Arrays.fill(endToCnt, -1);

    for (int[] requirement : requirements) {
      final int end = requirement[0];
      final int cnt = requirement[1];
      endToCnt[end + 1] = cnt;
    }

    // There's only one way to arrange a single number with zero inversions.
    dp[1][0] = 1;

    for (int i = 2; i <= n; ++i)
      for (int newInversions = 0; newInversions < i; ++newInversions)
        for (int j = 0; j + newInversions <= kMaxInversions; ++j) {
          final int inversionsAfterInsertion = j + newInversions;
          if (endToCnt[i] != -1 && inversionsAfterInsertion != endToCnt[i])
            continue;
          dp[i][inversionsAfterInsertion] += dp[i - 1][j];
          dp[i][inversionsAfterInsertion] %= kMod;
        }

    return dp[n][endToCnt[n]];
  }
}
