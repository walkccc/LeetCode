class Solution:
  def countSubarrays(self, nums: list[int], k: int) -> int:
    ans = 0
    summ = 0

    l = 0
    for r, num in enumerate(nums):
      summ += num
      while summ * (r - l + 1) >= k:
        summ -= nums[l]
        l += 1
      ans += r - l + 1

    return ans
