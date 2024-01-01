class Solution:
  def smallestRangeII(self, nums: List[int], k: int) -> int:
    nums.sort()

    ans = nums[-1] - nums[0]
    left = nums[0] + k
    right = nums[-1] - k

    for a, b in itertools.pairwise(nums):
      mini = min(left, b - k)
      maxi = max(right, a + k)
      ans = min(ans, maxi - mini)

    return ans
