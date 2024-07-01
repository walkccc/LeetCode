class Solution:
  def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
    ans = 0
    dp = 0

    def isOddEven(a: int, b: int) -> bool:
      return a % 2 != b % 2

    for i, num in enumerate(nums):
      if num > threshold:
        dp = 0
      elif i > 0 and dp > 0 and isOddEven(nums[i - 1], num):
        # Increase the size of the subarray.
        dp += 1
      else:
        # Start a new subarray if the start is valid.
        dp = 1 if num % 2 == 0 else 0
      ans = max(ans, dp)

    return ans
