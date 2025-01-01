class Solution:
  def minOperations(self, nums: list[int]) -> int:
    ans = 0

    for i in range(len(nums) - 2, -1, -1):
      if nums[i] > nums[i + 1]:
        minDivisor = self._getMinDivisor(nums[i])
        if minDivisor > nums[i + 1]:
          return -1
        nums[i] = minDivisor
        ans += 1

    return ans

  def _getMinDivisor(self, num: int) -> int:
    for divisor in range(2, math.isqrt(num) + 1):
      if num % divisor == 0:
        return divisor
    return num
