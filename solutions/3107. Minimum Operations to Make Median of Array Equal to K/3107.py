class Solution:
  def minOperationsToMakeMedianK(self, nums: list[int], k: int) -> int:
    n = len(nums)
    ans = 0

    nums.sort()

    for i in range(n // 2 + 1):
      ans += max(0, nums[i] - k)

    for i in range(n // 2, n):
      ans += max(0, k - nums[i])

    return ans
