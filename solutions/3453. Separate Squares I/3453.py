class Solution:
  def separateSquares(self, squares: list[list[int]]) -> float:
    area = 0
    width = 0
    prevHeight = 0
    total = sum((l**2 for _, _, l in squares))
    events = sorted([(y, True, l) for _, y, l in squares] +
                    [(y + l, False, l) for _, y, l in squares])

    for y, isStart, l in events:
      areaGain = width * (y - prevHeight)
      if area + areaGain >= total / 2:
        return prevHeight + (total / 2 - area) / width
      area += areaGain
      width += l if isStart else -l
      prevHeight = y
