# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
# Class BinaryMatrix(object):
#   def get(self, row: int, col: int) -> int:
#   def dimensions(self) -> List[int]:

class Solution:
  def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
    m, n = binaryMatrix.dimensions()
    ans = -1
    i = 0
    j = n - 1

    while i < m and j >= 0:
      if binaryMatrix.get(i, j):
        ans = j
        j -= 1
      else:
        i += 1

    return ans
