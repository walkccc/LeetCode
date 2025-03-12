class Solution:
  def minimizeArrayValue(self, nums: list[int]) -> int:
    ans = 0
    prefix = 0

    for i, num in enumerate(nums):
      prefix += num
      prefixAvg = math.ceil(prefix / (i + 1))
      ans = max(ans, prefixAvg)

    return ans
