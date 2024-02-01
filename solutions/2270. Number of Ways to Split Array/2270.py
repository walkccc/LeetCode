class Solution:
  def waysToSplitArray(self, nums: List[int]) -> int:
    ans = 0
    prefix = 0
    suffix = sum(nums)

    for i in range(len(nums) - 1):
      prefix += nums[i]
      suffix -= nums[i]
      if prefix >= suffix:
        ans += 1

    return ans
