class Solution:
  def distinctAverages(self, nums: list[int]) -> int:
    n = len(nums)
    sums = set()

    nums.sort()

    for i in range(n // 2):
      sums.add(nums[i] + nums[n - 1 - i])

    return len(sums)
