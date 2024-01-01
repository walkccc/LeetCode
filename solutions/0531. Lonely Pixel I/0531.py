class Solution:
  def findLonelyPixel(self, picture: List[List[str]]) -> int:
    m = len(picture)
    n = len(picture[0])
    ans = 0
    rows = [0] * m  # rows[i] := the number of B's in rows i
    cols = [0] * n  # cols[i] := the number of B's in cols i

    for i in range(m):
      for j in range(n):
        if picture[i][j] == 'B':
          rows[i] += 1
          cols[j] += 1

    for i in range(m):
      if rows[i] == 1:  # Only have to examine the rows if rows[i] == 1.
        for j in range(n):
          # After meeting a 'B' in this rows, break and search the next row.
          if picture[i][j] == 'B':
            if cols[j] == 1:
              ans += 1
            break

    return ans
