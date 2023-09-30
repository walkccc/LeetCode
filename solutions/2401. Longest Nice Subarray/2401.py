class Solution:
  def longestNiceSubarray(self, nums: List[int]) -> int:
    ans = 0
    usedBits = 0

    l = 0
    for r, num in enumerate(nums):
      while usedBits & num:
        usedBits ^= nums[l]
        l += 1
      usedBits |= num
      ans = max(ans, r - l + 1)

    return ans
