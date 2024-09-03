class Solution:
  def minDistance(
      self,
      height: int,
      width: int,
      tree: list[int],
      squirrel: list[int],
      nuts: list[list[int]],
  ) -> int:
    def dist(a: list[int], b: list[int]) -> int:
      return abs(a[0] - b[0]) + abs(a[1] - b[1])

    totDist = sum(dist(nut, tree) for nut in nuts) * 2
    maxSave = max(dist(nut, tree) - dist(nut, squirrel) for nut in nuts)
    return totDist - maxSave
