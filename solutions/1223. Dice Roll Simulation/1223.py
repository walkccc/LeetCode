class Solution:
  def dieSimulator(self, n: int, rollMax: list[int]) -> int:
    kMaxRolls = 15
    kMod = 1_000_000_007

    dp = [[[0] * (kMaxRolls + 1) for j in range(6)] for i in range(n + 1)]

    for num in range(6):
      dp[1][num][1] = 1

    for i in range(2, n + 1):
      for currNum in range(6):
        for prevNum in range(6):
          for k in range(1, 15 + 1):
            if prevNum != currNum:
              dp[i][currNum][1] = (
                  dp[i][currNum][1] + dp[i - 1][prevNum][k]) % kMod
            elif k < rollMax[currNum]:
              dp[i][currNum][k + 1] = dp[i - 1][currNum][k]

    ans = 0

    for num in range(6):
      for k in range(1, 15 + 1):
        ans += dp[n][num][k]

    return ans % kMod
