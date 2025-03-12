class Solution:
  def constructTransformedArray(self, nums: list[int]) -> list[int]:
    n = len(nums)
    return [nums[(i + num % n + n) % n]
            for i, num in enumerate(nums)]
