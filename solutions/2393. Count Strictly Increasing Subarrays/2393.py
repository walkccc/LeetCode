class Solution:
  def countSubarrays(self, nums: List[int]) -> int:
    ans = 0

    j = -1
    for i, num in enumerate(nums):
      if i > 0 and num <= nums[i - 1]:
        j = i - 1
      ans += i - j

    return ans
