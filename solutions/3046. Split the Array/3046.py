class Solution:
  def isPossibleToSplit(self, nums: List[int]) -> bool:
    return all(freq <= 2 for freq in collections.Counter(nums).values())
