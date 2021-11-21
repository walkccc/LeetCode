class Solution:
  def minSubArrayLen(self, s: int, nums: List[int]) -> int:
    ans = inf
    sum = 0
    j = 0

    for i, num in enumerate(nums):
      sum += num
      while sum >= s:
        ans = min(ans, i - j + 1)
        sum -= nums[j]
        j += 1

    return ans if ans != inf else 0
