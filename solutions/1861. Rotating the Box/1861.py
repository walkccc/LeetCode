class Solution:
  def rotateTheBox(self, box: list[list[str]]) -> list[list[str]]:
    m = len(box)
    n = len(box[0])
    rotated = [['.'] * m for _ in range(n)]

    for i in range(m):
      k = n - 1
      for j in reversed(range(n)):
        if box[i][j] != '.':
          if box[i][j] == '*':
            k = j
          rotated[k][m - i - 1] = box[i][j]
          k -= 1

    return [''.join(row) for row in rotated]
