class Solution:
  def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
    return reduce(operator.xor, arr1) & reduce(operator.xor, arr2)
