class Solution:
  def minimumDifference(self, nums: list[int], k: int) -> int:
    nums.sort()
    ans = nums[k - 1] - nums[0]

    for i in range(k, len(nums)):
      ans = min(ans, nums[i] - nums[i - k + 1])

    return ans
