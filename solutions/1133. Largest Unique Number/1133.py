class Solution:
  def largestUniqueNumber(self, nums: list[int]) -> int:
    return max([num for num, freq in collections.Counter(nums).items()
                if freq == 1], default=-1)
