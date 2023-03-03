class Solution:
  def maxDistance(self, arrays: List[List[int]]) -> int:
    min1, index_min1 = min((A[0], i) for i, A in enumerate(arrays))
    max1, index_max1 = max((A[-1], i) for i, A in enumerate(arrays))
    if index_min1 != index_max1:
      return max1 - min1

    min2, index_min2 = min((A[0], i)
                           for i, A in enumerate(arrays) if i != index_min1)
    max2, index_min2 = max((A[-1], i)
                           for i, A in enumerate(arrays) if i != index_max1)
    return max(max1 - min2, max2 - min1)
