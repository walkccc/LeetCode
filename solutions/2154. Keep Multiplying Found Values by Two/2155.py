class Solution:
  def findFinalValue(self, nums: List[int], original: int) -> int:
    numsSet = set(nums)
    while original in numsSet:
      original *= 2
    return original
