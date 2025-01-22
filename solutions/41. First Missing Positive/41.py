class Solution:
  def firstMissingPositive(self, nums: list[int]) -> int:
    n = len(nums)

    # Correct slot:
    # nums[i] = i + 1
    # nums[i] - 1 = i
    # nums[nums[i] - 1] = nums[i]
    for i in range(n):
      while nums[i] > 0 and nums[i] <= n and nums[nums[i] - 1] != nums[i]:
        nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

    for i, num in enumerate(nums):
      if num != i + 1:
        return i + 1

    return n + 1
