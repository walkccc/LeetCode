class Solution:
  def maxSum(self, nums: list[int]) -> int:
    ans = 0
    # maxNum[i] := the maximum num we met so far with the maximum digit i
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
