class Solution:
  def minDominoRotations(self, A: List[int], B: List[int]) -> int:
    for num in range(1, 7):
      if all(num in pair for pair in zip(A, B)):
        return len(A) - max(A.count(num), B.count(num))
    return -1
