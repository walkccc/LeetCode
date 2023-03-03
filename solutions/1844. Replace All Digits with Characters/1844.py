class Solution:
  def replaceDigits(self, s: str) -> str:
    A = list(s)

    for i in range(1, len(A), 2):
      A[i] = chr(ord(A[i - 1]) + ord(A[i]) - ord('0'))

    return ''.join(A)
