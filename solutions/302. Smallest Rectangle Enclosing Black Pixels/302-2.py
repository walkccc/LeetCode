class Solution:
  def minArea(self, image: list[list[str]], x: int, y: int) -> int:
    def firstAnyOne(l: int, r: int, allZeros: Callable[[int], bool]) -> int:
      while l < r:
        m = (l + r) // 2
        if allZeros(m):
          l = m + 1
        else:
          r = m
      return l

    def firstAllZeros(l: int, r: int, allZeros: Callable[[int], bool]) -> int:
      while l < r:
        m = (l + r) // 2
        if allZeros(m):
          r = m
        else:
          l = m + 1
      return l

    def colAllZeros(colIndex: int) -> bool:
      return all(pixel == '0' for pixel in list(zip(*image))[colIndex])

    def rowAllZeros(rowIndex: int) -> bool:
      return all(pixel == '0' for pixel in image[rowIndex])

    x1 = firstAnyOne(0, x, rowAllZeros)
    x2 = firstAllZeros(x + 1, len(image), rowAllZeros)
    y1 = firstAnyOne(0, y, colAllZeros)
    y2 = firstAllZeros(y + 1, len(image[0]), colAllZeros)
    return (x2 - x1) * (y2 - y1)
