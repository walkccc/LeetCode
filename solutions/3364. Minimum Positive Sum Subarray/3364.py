class Solution:
  def minimumSumSubarray(self, nums: list[int], l: int, r: int) -> int:
    ans = math.inf

    for windowSize in range(l, r + 1):
      windowSum = sum(nums[:windowSize])
      if windowSum > 0:
        ans = min(ans, windowSum)
      for i in range(windowSize, len(nums)):
        windowSum -= nums[i - windowSize]
        windowSum += nums[i]
        if windowSum > 0:
          ans = min(ans, windowSum)

    return -1 if ans == math.inf else ans
