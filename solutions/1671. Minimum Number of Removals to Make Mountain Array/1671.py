class Solution:
  def minimumMountainRemovals(self, nums: List[int]) -> int:
    left = self._lengthOfLIS(nums)
    right = self._lengthOfLIS(nums[::-1])[::-1]
    maxMountainSeq = 0

    for l, r in zip(left, right):
      if l > 1 and r > 1:
        maxMountainSeq = max(maxMountainSeq, l + r - 1)

    return len(nums) - maxMountainSeq

  def _lengthOfLIS(self, nums: List[int]) -> List[int]:
    # tail[i] := the minimum tail of all the increasing subsequences having
    # length i + 1
    # It's easy to see that tail must be an increasing array.
    tail = []
    # dp[i] := the length of LIS ending in nums[i]
    dp = []

    for num in nums:
      if not tail or num > tail[-1]:
        tail.append(num)
      else:
        tail[bisect.bisect_left(tail, num)] = num
      dp.append(len(tail))

    return dp
