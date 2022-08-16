class Solution:
  def findLonelyPixel(self, picture: List[List[str]]) -> int:
    m = len(picture)
    n = len(picture[0])
    ans = 0
    rows = [0] * m  # rows[i] := # of Bs in rows i
    cols = [0] * n  # cols[i] := # of Bs in cols i

    for i in range(m):
      for j in range(n):
        if picture[i][j] == 'B':
          rows[i] += 1
          cols[j] += 1

    for i in range(m):
      if rows[i] == 1:  # only have to examine the rows when rows[i] == 1
        for j in range(n):
          # after we met the 'B' in this rows, we break and search the next row
          if picture[i][j] == 'B':
            if cols[j] == 1:
              ans += 1
            break

    return ans
