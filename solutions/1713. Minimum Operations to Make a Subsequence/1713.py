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
    # tail[i] := the minimum tail of all the increasing subsequences having
    # length i + 1
    tail = []
    for num in nums:
      if not tail or num > tail[-1]:
        tail.append(num)
      else:
        tail[bisect.bisect_left(tail, num)] = num
    return len(tail)
