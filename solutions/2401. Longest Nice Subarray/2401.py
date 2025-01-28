class Solution:
  def longestNiceSubarray(self, nums: list[int]) -> int:
    ans = 0
    used = 0

    l = 0
    for r, num in enumerate(nums):
      while used & num:
        used ^= nums[l]
        l += 1
      used |= num
      ans = max(ans, r - l + 1)

    return ans
