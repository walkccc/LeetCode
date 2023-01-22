class Solution:
  def maxRotateFunction(self, nums: List[int]) -> int:
    f = sum(i * num for i, num in enumerate(nums))
    ans = f
    summ = sum(nums)

    for a in reversed(nums):
      f += summ - len(nums) * a
      ans = max(ans, f)

    return ans
