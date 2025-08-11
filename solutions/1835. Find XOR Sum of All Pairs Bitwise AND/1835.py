class Solution:
  def getXORSum(self, arr1: list[int], arr2: list[int]) -> int:
    return functools.reduce(
        operator.xor, arr1) & functools.reduce(
        operator.xor, arr2)
