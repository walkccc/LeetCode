class Solution:
  def canPartitionKSubsets(self, nums: list[int], k: int) -> bool:
    summ = sum(nums)
    if summ % k != 0:
      return False

    target = summ // k  # the target sum of each subset
    if any(num > target for num in nums):
      return False

    def dfs(s: int, remainingGroups: int, currSum: int, used: int) -> bool:
      if remainingGroups == 0:
        return True
      if currSum > target:
        return False
      if currSum == target:  # Find a valid group, so fresh start.
        return dfs(0, remainingGroups - 1, 0, used)

      for i in range(s, len(nums)):
        if used >> i & 1:
          continue
        if dfs(i + 1, remainingGroups, currSum + nums[i], used | 1 << i):
          return True

      return False

    nums.sort(reverse=True)
    return dfs(0, k, 0, 0)
