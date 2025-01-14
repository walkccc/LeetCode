class Solution:
  def resultGrid(
      self,
      image: list[list[int]],
      threshold: int,
  ) -> list[list[int]]:
    m = len(image)
    n = len(image[0])
    sums = [[0] * n for _ in range(m)]
    counts = [[0] * n for _ in range(m)]

    for i in range(m - 2):
      for j in range(n - 2):
        if self._isRegion(image, i, j, threshold):
          subgridSum = sum(image[x][y]
                           for x in range(i, i + 3)
                           for y in range(j, j + 3))
          for x in range(i, i + 3):
            for y in range(j, j + 3):
              sums[x][y] += subgridSum // 9
              counts[x][y] += 1

    for i in range(m):
      for j in range(n):
        if counts[i][j] > 0:
          image[i][j] = sums[i][j] // counts[i][j]

    return image

  def _isRegion(
      self,
      image: list[list[int]],
      i: int,
      j: int,
      threshold: int,
  ) -> bool:
    """Returns True if image[i..i + 2][j..j + 2] is a region."""
    for x in range(i, i + 3):
      for y in range(j, j + 3):
        if x > i and abs(image[x][y] - image[x - 1][y]) > threshold:
          return False
        if y > j and abs(image[x][y] - image[x][y - 1]) > threshold:
          return False
    return True
