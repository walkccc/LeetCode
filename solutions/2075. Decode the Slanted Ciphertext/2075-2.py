class Solution:
  def decodeCiphertext(self, encodedText: str, rows: int) -> str:
    n = len(encodedText)
    cols = n // rows

    ans = []

    for j in range(cols):
      for i in range(j, n, cols + 1):
        ans.append(encodedText[i])

    return ''.join(ans).rstrip()
