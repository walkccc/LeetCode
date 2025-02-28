class Solution:
  def minSubArrayLen(self, target: int, nums: list[int]) -> int:
    ans = math.inf
    summ = 0
    j = 0

    for i, num in enumerate(nums):
      summ += num
      while summ >= target:
        ans = min(ans, i - j + 1)
        summ -= nums[j]
        j += 1

    return 0 if ans == math.inf else ans
