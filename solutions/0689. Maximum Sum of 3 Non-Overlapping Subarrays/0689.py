class Solution:
  def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
    ans = [-1] * 3
    subarrayCount = len(nums) - k + 1
    dp = [0] * subarrayCount
    summ = 0

    for i, num in enumerate(nums):
      summ += num
      if i >= k:
        summ -= nums[i - k]
      if i >= k - 1:
        dp[i - k + 1] = summ

    left = [0] * subarrayCount
    maxIndex = 0

    for i in range(subarrayCount):
      if dp[i] > dp[maxIndex]:
        maxIndex = i
      left[i] = maxIndex

    right = [0] * subarrayCount
    maxIndex = subarrayCount - 1

    for i in reversed(range(subarrayCount)):
      if dp[i] >= dp[maxIndex]:
        maxIndex = i
      right[i] = maxIndex

    for i in range(k, subarrayCount - k):
      if ans[0] == -1 or dp[left[i - k]] + dp[i] + dp[right[i + k]] > dp[ans[0]] + dp[ans[1]] + dp[ans[2]]:
        ans = [left[i - k], i, right[i + k]]

    return ans
