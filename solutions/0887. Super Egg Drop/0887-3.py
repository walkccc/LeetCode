class Solution:
  def superEggDrop(self, K: int, N: int) -> int:
    moves = 0
    dp = [[0] * (K + 1) for _ in range(N + 1)]

    while dp[moves][K] < N:
      moves += 1
      for eggs in range(1, K + 1):
        dp[moves][eggs] = dp[moves - 1][eggs - 1] + \
            dp[moves - 1][eggs] + 1

    return moves
