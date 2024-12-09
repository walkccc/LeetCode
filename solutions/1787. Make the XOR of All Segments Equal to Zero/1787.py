class Solution:
  def minChanges(self, nums: list[int], k: int) -> int:
    kMax = 1024
    n = len(nums)
    # counts[i] := the counter that maps at the i-th position
    counts = [collections.Counter() for _ in range(k)]
    # dp[i][j] := the minimum number of elements to change s.t. XOR(nums[i..k - 1]) is j
    dp = [[n] * kMax for _ in range(k)]

    for i, num in enumerate(nums):
      counts[i % k][num] += 1

    def countAt(i: int) -> int:
      return n // k + (1 if n % k > i else 0)

    # Initialize the DP array.
    for j in range(kMax):
      dp[k - 1][j] = countAt(k - 1) - counts[k - 1][j]

    for i in range(k - 2, -1, -1):
      # The worst-case scenario is changing all the i-th position numbers to a
      # non-existent value in the current bucket.
      changeAll = countAt(i) + min(dp[i + 1])
      for j in range(kMax):
        dp[i][j] = changeAll
        for num, freq in counts[i].items():
          # the cost to change every number in the i-th position to `num`
          cost = countAt(i) - freq
          dp[i][j] = min(dp[i][j], dp[i + 1][j ^ num] + cost)

    return dp[0][0]
