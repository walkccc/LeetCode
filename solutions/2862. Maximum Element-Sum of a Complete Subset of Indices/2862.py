class Solution:
  def maximumSum(self, nums: List[int]) -> int:
    ans = 0
    oddPowerToSum = collections.Counter()

    def divideSquares(val: int) -> int:
      for num in range(2, val + 1):
        while val % (num * num) == 0:
          val //= (num * num)
      return val

    for i, num in enumerate(nums):
      oddPower = divideSquares(i + 1)
      oddPowerToSum[oddPower] += num
      ans = max(ans, oddPowerToSum[oddPower])

    return ans
