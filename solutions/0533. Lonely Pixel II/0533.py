class Solution:
  def findBlackPixel(self, picture: List[List[str]], target: int) -> int:
    m = len(picture)
    n = len(picture[0])
    ans = 0
    rows = [row.count('B') for row in picture]
    cols = [col.count('B') for col in zip(*picture)]
    rowStrings = [''.join(row) for row in picture]
    countRowStrings = Counter(rowStrings)

    for i, (row, stringRow) in enumerate(zip(rows, rowStrings)):
      if row == target and countRowStrings[stringRow] == target:
        for j, col in enumerate(cols):
          if picture[i][j] == 'B' and col == target:
            ans += 1

    return ans
