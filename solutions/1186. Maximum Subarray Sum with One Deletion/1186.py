class Solution:
  # Very similar to 53. Maximum Subarray
  def maximumSum(self, arr: List[int]) -> int:
    # dp[0][i] := the maximum sum subarray ending in i (no deletion)
    # dp[1][i] := the maximum sum subarray ending in i (at most 1 deletion)
    dp = [[0] * len(arr) for _ in range(2)]

    dp[0][0] = arr[0]
    dp[1][0] = arr[0]
    for i in range(1, len(arr)):
      dp[0][i] = max(arr[i], dp[0][i - 1] + arr[i])
      dp[1][i] = max(arr[i], dp[1][i - 1] + arr[i], dp[0][i - 1])

    return max(dp[1])
