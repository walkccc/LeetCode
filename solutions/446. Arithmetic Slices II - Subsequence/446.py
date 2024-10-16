class Solution:
  def numberOfArithmeticSlices(self, nums: list[int]) -> int:
    n = len(nums)
    ans = 0
    # dp[i][j] := the number of subsequences end in nums[j] nums[i]
    dp = [[0] * n for _ in range(n)]
    numToIndices = collections.defaultdict(list)

    for i, num in enumerate(nums):
      numToIndices[num].append(i)

    for i in range(n):
      for j in range(i):
        target = nums[j] * 2 - nums[i]
        if target in numToIndices:
          for k in numToIndices[target]:
            if k < j:
              dp[i][j] += dp[j][k] + 1
        ans += dp[i][j]

    return ans
