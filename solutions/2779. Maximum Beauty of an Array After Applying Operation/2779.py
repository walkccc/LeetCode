class Solution:
  def maximumBeauty(self, nums: List[int], k: int) -> int:
    ans = 0

    nums.sort()

    l = 0
    for r in range(len(nums)):
      while nums[r] - nums[l] > 2 * k:
        l += 1
      ans = max(ans, r - l + 1)

    return ans
