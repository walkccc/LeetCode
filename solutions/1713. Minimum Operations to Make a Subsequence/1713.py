class Solution:
  def minOperations(self, target: list[int], arr: list[int]) -> int:
    indices = []
    numToIndex = {num: i for i, num in enumerate(target)}

    for a in arr:
      if a in numToIndex:
        indices.append(numToIndex[a])

    return len(target) - self._lengthOfLIS(indices)

  # Same as 300. Longest Increasing Subsequence
  def _lengthOfLIS(self, nums: list[int]) -> int:
    # tails[i] := the minimum tail of all the increasing subsequences having
    # length i + 1
    tails = []
    for num in nums:
      if not tails or num > tails[-1]:
        tails.append(num)
      else:
        tails[bisect.bisect_left(tails, num)] = num
    return len(tails)
