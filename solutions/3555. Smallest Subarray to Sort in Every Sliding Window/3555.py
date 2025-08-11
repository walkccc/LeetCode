class Solution:
  def minSubarraySort(self, nums: list[int], k):
    ans = []

    for i in range(len(nums) - k + 1):
      window = nums[i:i+k]
      sortedWindow = sorted(window)
      l = 0
      r = k - 1
      while l < k and window[l] == sortedWindow[l]:
        l += 1
      while r >= 0 and window[r] == sortedWindow[r]:
        r -= 1
      ans.append(0 if l > r else r - l + 1)

    return ans
