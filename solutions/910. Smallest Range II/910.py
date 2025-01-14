class Solution:
  def smallestRangeII(self, nums: list[int], k: int) -> int:
    nums.sort()

    ans = nums[-1] - nums[0]
    left = nums[0] + k
    right = nums[-1] - k

    for a, b in itertools.pairwise(nums):
      mn = min(left, b - k)
      mx = max(right, a + k)
      ans = min(ans, mx - mn)

    return ans
