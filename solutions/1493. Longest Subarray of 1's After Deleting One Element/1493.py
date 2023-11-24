class Solution:
  def longestSubarray(self, nums: List[int]) -> int:
    ans = 0
    count0 = 0

    l = 0
    for r, num in enumerate(nums):
      if num == 0:
        count0 += 1
      while count0 == 2:
        if nums[l] == 0:
          count0 -= 1
        l += 1
      ans = max(ans, r - l)

    return ans
