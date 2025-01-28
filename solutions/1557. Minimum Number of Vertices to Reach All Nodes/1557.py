class Solution:
  def findSmallestSetOfVertices(
      self,
      n: int,
      edges: list[list[int]],
  ) -> list[int]:
    inDegrees = [0] * n

    for _, v in edges:
      inDegrees[v] += 1

    return [i for i, d in enumerate(inDegrees) if d == 0]
