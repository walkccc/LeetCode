class Solution:
  def lenLongestFibSubseq(self, arr: list[int]) -> int:
    n = len(arr)
    ans = 0
    numToIndex = {a: i for i, a in enumerate(arr)}
    dp = [[2] * n for _ in range(n)]

    for j in range(n):
      for k in range(j + 1, n):
        ai = arr[k] - arr[j]
        if ai < arr[j] and ai in numToIndex:
          i = numToIndex[ai]
          dp[j][k] = dp[i][j] + 1
          ans = max(ans, dp[j][k])

    return ans
