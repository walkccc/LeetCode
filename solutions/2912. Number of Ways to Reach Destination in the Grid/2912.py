class Solution:
  def numberOfWays(
      self,
      n: int,
      m: int,
      k: int,
      source: list[int],
      dest: list[int],
  ) -> int:
    kMod = 1_000_000_007
    # dp[i][0] := the the number of ways of `source` to `dest` using i steps
    # dp[i][1] := the the number of ways of `source` to dest's row using i steps
    # dp[i][2] := the the number of ways of `source` to dest's col using i steps
    # dp[i][3] := the the number of ways of `source` to others using i steps
    dp = [[0] * 4 for _ in range(k + 1)]
    if source == dest:
      dp[0][0] = 1
    elif source[0] == dest[0]:
      dp[0][1] = 1
    elif source[1] == dest[1]:
      dp[0][2] = 1
    else:
      dp[0][3] = 1

    for i in range(1, k + 1):
      dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % kMod
      dp[i][1] = (dp[i - 1][0] * (m - 1) +  # -self
                  dp[i - 1][1] * (m - 2) +  # -self, -center
                  dp[i - 1][3]) % kMod
      dp[i][2] = (dp[i - 1][0] * (n - 1) +  # -self
                  dp[i - 1][2] * (n - 2) +  # -self, -center
                  dp[i - 1][3]) % kMod
      dp[i][3] = (dp[i - 1][1] * (n - 1) +  # -self
                  dp[i - 1][2] * (m - 1) +  # -self
                  dp[i - 1][3] * (m + n - 1 - 3)) % kMod  # -self, -row, -col

    return dp[k][0]
