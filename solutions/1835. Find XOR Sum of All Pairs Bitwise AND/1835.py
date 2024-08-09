class Solution:
  def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
    return functools.reduce(operator.xor, arr1) & functools.reduce(operator.xor, arr2)
