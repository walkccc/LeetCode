class Solution:
  def maxFrequencyScore(self, nums: list[int], k: int) -> int:
    nums.sort()
    ans = 0
    cost = 0

    l = 0
    for r, num in enumerate(nums):
      cost += num - nums[(l + r) // 2]
      while cost > k:
        cost -= nums[(l + r + 1) // 2] - nums[l]
        l += 1
      ans = max(ans, r - l + 1)

    return ans
