class Solution:
  def sortedSquares(self, nums: list[int]) -> list[int]:
    n = len(nums)
    l = 0
    r = n - 1
    ans = [0] * n

    while n:
      n -= 1
      if abs(nums[l]) > abs(nums[r]):
        ans[n] = nums[l] * nums[l]
        l += 1
      else:
        ans[n] = nums[r] * nums[r]
        r -= 1

    return ans
