class Solution:
  def distinctAverages(self, nums: List[int]) -> int:
    n = len(nums)
    sums = set()

    nums.sort()

    for i in range(n // 2):
      sums.add(nums[i] + nums[n - i - 1])

    return len(sums)
