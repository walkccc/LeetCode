class Solution:
  def maxPathLength(self, coordinates: list[list[int]], k: int) -> int:
    xk, yk = coordinates[k]
    leftCoordinates = [(x, y) for x, y in coordinates if x < xk and y < yk]
    rightCoordinates = [(x, y) for x, y in coordinates if x > xk and y > yk]
    return (1 +
            self._lengthOfLIS(leftCoordinates) +
            self._lengthOfLIS(rightCoordinates))

  # Similar to 300. Longest Increasing Subsequence
  def _lengthOfLIS(self, coordinates: list[tuple[int, int]]) -> int:
    coordinates.sort(key=lambda x: (x[0], -x[1]))
    # tail[i] := the minimum tail of all the increasing subsequences having
    # length i + 1
    tail = []
    for _, y in coordinates:
      if not tail or y > tail[-1]:
        tail.append(y)
      else:
        tail[bisect.bisect_left(tail, y)] = y
    return len(tail)
