class Solution:
  def goodSubsetofBinaryMatrix(self, grid: list[list[int]]) -> list[int]:
    kMaxBit = 30
    maskToIndex = {}

    def getMask(row: list[int]) -> int:
      mask = 0
      for i, num in enumerate(row):
        if num == 1:
          mask |= 1 << i
      return mask

    for i, row in enumerate(grid):
      mask = getMask(row)
      if mask == 0:
        return [i]
      for prevMask in range(1, kMaxBit):
        if (mask & prevMask) == 0 and prevMask in maskToIndex:
          return [maskToIndex[prevMask], i]
      maskToIndex[mask] = i

    return []
