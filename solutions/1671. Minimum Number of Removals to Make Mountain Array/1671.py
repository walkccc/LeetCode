class Solution:
  def minimumMountainRemovals(self, nums: list[int]) -> int:
    left = self._lengthOfLIS(nums)
    right = self._lengthOfLIS(nums[::-1])[::-1]
    maxMountainSeq = 0

    for l, r in zip(left, right):
      if l > 1 and r > 1:
        maxMountainSeq = max(maxMountainSeq, l + r - 1)

    return len(nums) - maxMountainSeq

  # Similar to 300. Longest Increasing Subsequence
  def _lengthOfLIS(self, nums: list[int]) -> list[int]:
    # tails[i] := the minimum tail of all the increasing subsequences having
    # length i + 1
    tails = []
    # dp[i] := the length of LIS ending in nums[i]
    dp = []
    for num in nums:
      if not tails or num > tails[-1]:
        tails.append(num)
      else:
        tails[bisect.bisect_left(tails, num)] = num
      dp.append(len(tails))
    return dp
