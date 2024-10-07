class Solution:
  def decodeCiphertext(self, encodedText: str, rows: int) -> str:
    n = len(encodedText)
    cols = n // rows

    ans = []
    matrix = [[' '] * cols for _ in range(rows)]

    for i in range(rows):
      for j in range(cols):
        matrix[i][j] = encodedText[i * cols + j]

    for col in range(cols):
      i = 0
      j = col
      while i < rows and j < cols:
        ans.append(matrix[i][j])
        i += 1
        j += 1

    return ''.join(ans).rstrip()
