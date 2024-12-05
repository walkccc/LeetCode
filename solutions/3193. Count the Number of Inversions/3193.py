class Solution:
  def numberOfPermutations(self, n: int, requirements: list[list[int]]) -> int:
    kMod = 1_000_000_007
    kMaxInversions = 400
    # dp[i][j] := the number of ways to arrange the first i numbers of the
    # permutation s.t. there are j inversions
    dp = [[0] * (kMaxInversions + 1) for _ in range(n + 1)]
    endToCnt = {end + 1: cnt for end, cnt in requirements}

    # There's only one way to arrange a single number with zero inversions.
    dp[1][0] = 1

    for i in range(2, n + 1):
      for newInversions in range(i):
        for j in range(kMaxInversions - newInversions + 1):
          inversionsAfterInsertion = j + newInversions
          if i in endToCnt and inversionsAfterInsertion != endToCnt[i]:
            continue
          dp[i][inversionsAfterInsertion] += dp[i - 1][j]
          dp[i][inversionsAfterInsertion] %= kMod

    return dp[n][endToCnt[n]]
