class Solution:
  def maxFrequency(self, nums: List[int], k: int) -> int:
    ans = 0
    sum = 0

    nums.sort()

    l = 0
    for r, num in enumerate(nums):
      sum += num
      while sum + k < num * (r - l + 1):
        sum -= nums[l]
        l += 1
      ans = max(ans, r - l + 1)

    return ans
