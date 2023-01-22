class Solution:
  def minDistance(self, height: int, width: int, tree: List[int], squirrel: List[int], nuts: List[List[int]]) -> int:
    def dist(a: List[int], b: List[int]) -> int:
      return abs(a[0] - b[0]) + abs(a[1] - b[1])

    totDist = sum(dist(nut, tree) for nut in nuts) * 2
    maxSave = max(dist(nut, tree) - dist(nut, squirrel) for nut in nuts)
    return totDist - maxSave
