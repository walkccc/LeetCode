class Solution:
  def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
    prefix = list(itertools.accumulate(nums))
    suffix = list(itertools.accumulate(nums[::-1]))[::-1]
    return [num * (i + 1) - prefix[i] + suffix[i] - num * (len(nums) - i)
            for i, num in enumerate(nums)]
