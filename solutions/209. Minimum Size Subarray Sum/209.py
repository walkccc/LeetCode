class Solution:
  def minSubArrayLen(self, s: int, nums: list[int]) -> int:
    ans = math.inf
    summ = 0
    j = 0

    for i, num in enumerate(nums):
      summ += num
      while summ >= s:
        ans = min(ans, i - j + 1)
        summ -= nums[j]
        j += 1

    return ans if ans != math.inf else 0
