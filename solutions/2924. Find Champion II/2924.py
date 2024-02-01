class Solution:
  def findChampion(self, n: int, edges: List[List[int]]) -> int:
    inDegrees = [0] * n

    for _, v in edges:
      inDegrees[v] += 1

    return -1 if inDegrees.count(0) > 1 \
        else inDegrees.index(0)
