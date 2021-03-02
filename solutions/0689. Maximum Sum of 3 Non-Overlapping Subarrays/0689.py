class Solution:
  def maxSumOfThreeSubarrays(self, nums, k):
    ans = [-1] * 3
    subarrayCount = len(nums) - k + 1
    dp = [0] * subarrayCount
    sum = 0

    for i, num in enumerate(nums):
      sum += num
      if i >= k:
        sum -= nums[i - k]
      if i >= k - 1:
        dp[i - k + 1] = sum

    left = [0] * subarrayCount
    maxIndex = 0

    for i in range(subarrayCount):
      if dp[i] > dp[maxIndex]:
        maxIndex = i
      left[i] = maxIndex

    right = [0] * subarrayCount
    maxIndex = subarrayCount - 1

    for i in range(subarrayCount - 1, -1, -1):
      if dp[i] >= dp[maxIndex]:
        maxIndex = i
      right[i] = maxIndex

    for i in range(k, subarrayCount - k):
      if ans[0] == -1 or dp[left[i - k]] + dp[i] + dp[right[i + k]] > dp[ans[0]] + dp[ans[1]] + dp[ans[2]]:
        ans = [left[i - k], i, right[i + k]]

    return ans
