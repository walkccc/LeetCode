class Solution:
  def minimumDistance(self, points: list[list[int]]) -> int:
    i, j = self._maxManhattanDistance(points, -1)
    xi, yi = self._maxManhattanDistance(points, i)
    xj, yj = self._maxManhattanDistance(points, j)
    return min(self._manhattan(points, xi, yi),
               self._manhattan(points, xj, yj))

  def _maxManhattanDistance(
      self,
      points: list[list[int]],
      excludedIndex: int,
  ) -> int:
    minSum = math.inf
    maxSum = -math.inf
    minDiff = math.inf
    maxDiff = -math.inf
    minSumIndex = -1
    maxSumIndex = -1
    minDiffIndex = -1
    maxDiffIndex = -1

    for i, (x, y) in enumerate(points):
      if i == excludedIndex:
        continue
      summ = x + y
      diff = x - y
      if summ < minSum:
        minSum = summ
        minSumIndex = i
      if summ > maxSum:
        maxSum = summ
        maxSumIndex = i
      if diff < minDiff:
        minDiff = diff
        minDiffIndex = i
      if diff > maxDiff:
        maxDiff = diff
        maxDiffIndex = i

    return ([minSumIndex, maxSumIndex] if maxSum - minSum >= maxDiff - minDiff
            else [minDiffIndex, maxDiffIndex])

  def _manhattan(self, points: list[list[int]], i: int, j: int) -> int:
    return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
