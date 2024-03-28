class Solution:
  def minDifference(self, nums: List[int]) -> int:
    n = len(nums)
    if n < 5:
      return 0

    ans = math.inf

    nums.sort()

    # 1. Change nums[0..i) to nums[i].
    # 2. Change nums[n - 3 + i..n) to nums[n - 4 + i].
    for i in range(4):
      ans = min(ans, nums[n - 4 + i] - nums[i])

    return ans
