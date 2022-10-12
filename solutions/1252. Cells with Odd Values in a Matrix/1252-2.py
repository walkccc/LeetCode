class Solution:
  def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
    # rows[i] and cols[i] :=
    #   True (flipped even times) // False (flipped odd times)
    rows = [False] * m
    cols = [False] * n

    for r, c in indices:
      rows[r] ^= True
      cols[c] ^= True

    oddRowsCount = rows.count(True)
    oddColsCount = cols.count(True)
    evenRowsCount = m - oddRowsCount
    evenColsCount = n - oddColsCount
    return oddRowsCount * evenColsCount + oddColsCount * evenRowsCount
