class Solution:
  def twoSumLessThanK(self, nums: List[int], k: int) -> int:
    if len(nums) < 2:
      return -1

    ans = -1  # Note the constrathat nums[i] > 0.
    l = 0
    r = len(nums) - 1

    nums.sort()

    while l < r:
      if nums[l] + nums[r] < k:
        ans = max(ans, nums[l] + nums[r])
        l += 1
      else:
        r -= 1

    return ans
