class Solution:
  def countCells(self, grid: list[list[str]], pattern: str) -> int:
    BASE = 13
    HASH = 1_000_000_007
    m = len(grid)
    n = len(grid[0])

    def markMatchedCells(flattenedGrid: str, isHorizontal: bool) -> list[list[bool]]:
      matchMatrix = [[False] * n for _ in range(m)]
      matchPrefix = [0] * (len(flattenedGrid) + 1)
      pows = [1]  # pows[i] := BASE^i % HASH
      patternHash = 0
      runningHash = 0

      for i in range(1, len(pattern)):
        pows.append((pows[-1] * BASE) % HASH)

      for c in pattern:
        patternHash = (patternHash * BASE + (ord(c) - ord('a'))) % HASH

      for i in range(len(flattenedGrid)):
        runningHash = (
            runningHash * BASE + (ord(flattenedGrid[i]) - ord('a'))) % HASH
        if i >= len(pattern) - 1:
          if runningHash == patternHash:  # Match found.
            matchPrefix[i - len(pattern) + 1] += 1
            matchPrefix[i + 1] -= 1
          # Remove the contribution of the oldest letter.
          oldestLetterHash = (
              pows[len(pattern) - 1] *
              (ord(flattenedGrid[i - len(pattern) + 1]) - ord('a'))) % HASH
          runningHash = (runningHash - oldestLetterHash + HASH) % HASH

      for k in range(len(flattenedGrid)):
        if k > 0:
          matchPrefix[k] += matchPrefix[k - 1]
        if matchPrefix[k] > 0:
          i = k // n if isHorizontal else k % m
          j = k % n if isHorizontal else k // m
          matchMatrix[i][j] = True

      return matchMatrix

    # Find matching positions.
    flattenedGridRow = ''.join(cell for row in grid for cell in row)
    flattenedGridCol = ''.join(cell for col in zip(*grid) for cell in col)
    horizontalMatches = markMatchedCells(flattenedGridRow, True)
    verticalMatches = markMatchedCells(flattenedGridCol, False)
    return sum(horizontalMatches[i][j] and verticalMatches[i][j]
               for i in range(m)
               for j in range(n))
