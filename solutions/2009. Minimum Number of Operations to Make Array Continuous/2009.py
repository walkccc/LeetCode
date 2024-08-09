class Solution:
  def minOperations(self, nums: List[int]) -> int:
    n = len(nums)
    ans = n
    nums = sorted(set(nums))

    for i, start in enumerate(nums):
      end = start + n - 1
      index = bisect_right(nums, end)
      uniqueLength = index - i
      ans = min(ans, n - uniqueLength)

    return ans
