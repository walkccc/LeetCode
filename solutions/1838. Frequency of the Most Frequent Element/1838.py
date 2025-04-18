class Solution:
  def maxFrequency(self, nums: list[int], k: int) -> int:
    ans = 0
    summ = 0

    nums.sort()

    l = 0
    for r, num in enumerate(nums):
      summ += num
      while summ + k < num * (r - l + 1):
        summ -= nums[l]
        l += 1
      ans = max(ans, r - l + 1)

    return ans
