class Solution:
  def maximumBobPoints(
      self,
      numArrows: int,
      aliceArrows: list[int],
  ) -> list[int]:
    allMask = (1 << 12) - 1
    maxPoint = 0
    maxMask = 0

    def getShotableAndPoint(mask: int, leftArrows: int) -> tuple[bool, int]:
      point = 0
      for i in range(12):
        if mask >> i & 1:
          leftArrows -= aliceArrows[i] + 1
          point += i
      return leftArrows >= 0, point

    for mask in range(allMask):
      shotable, point = getShotableAndPoint(mask, numArrows)
      if shotable and point > maxPoint:
        maxPoint = point
        maxMask = mask

    def getBobsArrows(mask: int, leftArrows: int) -> list[int]:
      bobsArrows = [0] * 12
      for i in range(12):
        if mask >> i & 1:
          bobsArrows[i] = aliceArrows[i] + 1
          leftArrows -= aliceArrows[i] + 1
      bobsArrows[0] = leftArrows
      return bobsArrows

    return getBobsArrows(maxMask, numArrows)
