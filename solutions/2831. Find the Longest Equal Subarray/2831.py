class Solution:
  def longestEqualSubarray(self, nums: list[int], k: int) -> int:
    ans = 0
    count = collections.Counter()

    l = 0
    for r, num in enumerate(nums):
      count[num] += 1
      ans = max(ans, count[num])
      while r - l + 1 - k > ans:
        count[nums[l]] -= 1
        l += 1

    return ans
