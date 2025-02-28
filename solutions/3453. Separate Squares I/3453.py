class Solution:
  def separateSquares(self, squares: list[list[int]]) -> float:
    halfArea = sum((l**2 for _, _, l in squares)) / 2
    events = sorted([(y, True, l) for _, y, l in squares] +
                    [(y + l, False, l) for _, y, l in squares])
    area = 0
    width = 0
    prevY = 0

    for y, isStart, l in events:
      areaGain = width * (y - prevY)
      if area + areaGain >= halfArea:
        return prevY + (halfArea - area) / width
      area += areaGain
      width += l if isStart else -l
      prevY = y
