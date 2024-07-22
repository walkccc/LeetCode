class Solution:
  def minimumMoves(self, arr: List[int]) -> int:
    n = len(arr)
    # dp[i][j] := the minimum number of moves to remove all numbers from arr[i..j]
    dp = [[n] * n for _ in range(n)]

    for i in range(n):
      dp[i][i] = 1

    for i in range(n - 1):
      dp[i][i + 1] = 1 if arr[i] == arr[i + 1] else 2

    for d in range(2, n):
      for i in range(n - d):
        j = i + d
        # Remove arr[i] and arr[j] within the move of removing
        # arr[i + 1..j - 1]
        if arr[i] == arr[j]:
          dp[i][j] = dp[i + 1][j - 1]
        # Try all the possible partitions.
        for k in range(i, j):
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j])

    return dp[0][n - 1]
