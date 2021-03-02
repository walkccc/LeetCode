class Solution:
  def smallestRangeI(self, A: List[int], K: int) -> int:
    return max(0, max(A) - min(A) - 2 * K)
