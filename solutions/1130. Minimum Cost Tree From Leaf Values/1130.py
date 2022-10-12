class Solution:
  def mctFromLeafValues(self, arr: List[int]) -> int:
    n = len(arr)
    # dp[i][j] := min cost of arr[i..j]
    dp = [[0] * n for _ in range(n)]
    # maxVal[i][j] := max value of arr[i..j]
    maxVal = [[0] * n for _ in range(n)]

    for i in range(n):
      maxVal[i][i] = arr[i]

    for d in range(1, n):
      for i in range(n - d):
        j = i + d
        maxVal[i][j] = max(maxVal[i][j - 1], maxVal[i + 1][j])

    for d in range(1, n):
      for i in range(n - d):
        j = i + d
        dp[i][j] = math.inf
        for k in range(i, j):
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] +
                         maxVal[i][k] * maxVal[k + 1][j])

    return dp[0][-1]
