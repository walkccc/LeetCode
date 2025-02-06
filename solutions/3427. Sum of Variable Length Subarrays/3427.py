class Solution:
  def subarraySum(self, nums: list[int]) -> int:
    prefix = list(itertools.accumulate(nums, initial=0))
    return sum(prefix[i + 1] - prefix[max(0, i - num)]
               for i, num in enumerate((nums)))
