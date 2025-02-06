class Solution:
  def minOperations(self, nums: list[int]) -> int:
    return self._lengthOfLIS(nums[::-1])

  def _lengthOfLIS(self, nums: list[int]) -> int:
    # tails[i] := the minimum tail of all the increasing subsequences having
    # length i + 1
    tails = []
    for num in nums:
      if not tails or num >= tails[-1]:
        tails.append(num)
      else:
        tails[bisect.bisect_right(tails, num)] = num
    return len(tails)
