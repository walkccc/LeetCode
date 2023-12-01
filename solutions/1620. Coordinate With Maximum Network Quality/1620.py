class Solution:
  def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
    kMax = 50
    n = len(towers)
    ans = [0] * 2
    maxQuality = 0

    def dist(tower: List[int], i: int, j: int) -> float:
      """Returns the distance between the tower and the coordinate."""
      return math.sqrt((tower[0] - i)**2 + (tower[1] - j)**2)

    for i in range(kMax + 1):
      for j in range(kMax + 1):
        qualitySum = 0
        for tower in towers:
          q = tower[2]
          d = dist(tower, i, j)
          if d <= radius:
            qualitySum += int(q / (1 + d))
        if qualitySum > maxQuality:
          maxQuality = qualitySum
          ans = [i, j]

    return ans
