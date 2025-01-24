class Solution:
  def maxPointsInsideSquare(self, points: list[list[int]], s: str) -> int:
    secondMinSize = math.inf
    minSizes = {}

    for (x, y), c in zip(points, s):
      sz = max(abs(x), abs(y))
      if c not in minSizes:
        minSizes[c] = sz
      elif sz < minSizes[c]:
        # This is because minSizes[j] is about to be replaced by a smaller
        # value, so it becomes a candidate for the second minimum size.
        secondMinSize = min(secondMinSize, minSizes[c])
        minSizes[c] = sz
      else:
        # `sz` is not smaller than the current minimum size, but it could be
        # smaller than the current second minimum size.
        secondMinSize = min(secondMinSize, sz)

    return sum(sz < secondMinSize for sz in minSizes.values())
