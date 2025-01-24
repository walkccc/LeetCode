class Solution:
  def movesToMakeZigzag(self, nums: list[int]) -> int:
    decreasing = [0] * 2

    for i, num in enumerate(nums):
      l = nums[i - 1] if i > 0 else 1001
      r = nums[i + 1] if i + 1 < len(nums) else 1001
      decreasing[i % 2] += max(0, num - min(l, r) + 1)

    return min(decreasing[0], decreasing[1])
