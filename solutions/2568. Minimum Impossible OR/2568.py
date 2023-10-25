class Solution:
  def minImpossibleOR(self, nums: List[int]) -> int:
    ans = 1
    numsSet = set(nums)

    while ans in numsSet:
      ans <<= 1

    return ans
