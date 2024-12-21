class Solution:
  def countOfPairs(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    kMax = 1000
    n = len(nums)
    # dp[i][num] := the number of valid ways to fill the arrays up to index i
    # with arr1[i] = num
    dp = [[0] * (kMax + 1) for _ in range(n)]

    for num in range(nums[0] + 1):
      dp[0][num] = 1

    for i in range(1, n):
      ways = 0
      prevNum = 0
      # To satisfy arr1, prevNum <= num.
      # To satisfy arr2, nums[i - 1] - prevNum >= nums[i] - num.
      #               => prevNum <= min(num, num - (nums[i] - nums[i - 1])).
      # As we move from `num` to `num + 1`, the range of valid `prevNum` values
      # becomes prevNum <= min(num + 1, num + 1 - (nums[i] - nums[i - 1])).
      # Since the range of `prevNum` can only increase by at most 1, there's
      # no need to iterate through all possible values of `prevNum`. We can
      # simply increment `prevNum` by 1 if it meets the condition.
      for num in range(nums[i] + 1):
        if prevNum <= min(num, num - (nums[i] - nums[i - 1])):
          ways = (ways + dp[i - 1][prevNum]) % kMod
          prevNum += 1
        dp[i][num] = ways

    return sum(dp[n - 1]) % kMod
