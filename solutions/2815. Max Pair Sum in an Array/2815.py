class Solution:
  def maxSum(self, nums: List[int]) -> int:
    ans = 0
    # maxNum[i] := max num we met so far with max digit i
    maxNum = [0] * 10

    def getMaxDigit(num: int) -> int:
      maxDigit = 0
      while num > 0:
        maxDigit = max(maxDigit, num % 10)
        num //= 10
      return maxDigit

    for num in nums:
      d = getMaxDigit(num)
      if maxNum[d] > 0:
        ans = max(ans, num + maxNum[d])
      maxNum[d] = max(maxNum[d], num)

    return -1 if ans == 0 else ans
