# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
# class BinaryMatrix(object):
#   def get(self, row: int, col: int) -> int:
#   def dimensions(self) -> List[int]:

class Solution:
  def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
    m, n = binaryMatrix.dimensions()
    ans = -1
    l = 0
    r = n - 1

    while l <= r:
      mid = (l + r) // 2
      if any(binaryMatrix.get(i, mid) for i in range(m)):
        ans = mid
        r = mid - 1
      else:
        l = mid + 1

    return ans
