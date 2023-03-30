class Solution:
  def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
    for _ in range(4):
      if mat == target:
        return True
      mat = [list(x) for x in zip(*mat[::-1])]
    return False
