class Solution:
  def semiOrderedPermutation(self, nums: list[int]) -> int:
    n = len(nums)
    index1 = nums.index(1)
    indexN = nums.index(n)
    return index1 + (n - 1 - indexN) - int(index1 > indexN)
