class Solution:
  def maxSubarrayLength(self, nums: list[int], k: int) -> int:
    ans = 0
    count = collections.Counter()

    l = 0
    for r, num in enumerate(nums):
      count[num] += 1
      while count[num] == k + 1:
        count[nums[l]] -= 1
        l += 1
      ans = max(ans, r - l + 1)

    return ans
