class Solution:
  def isGood(self, nums: List[int]) -> bool:
    n = len(nums) - 1
    count = collections.Counter(nums)
    return all(count[i] == 1 for i in range(1, n)) and count[n] == 2
