class Solution:
  def repeatedStringMatch(self, A: str, B: str) -> int:
    n = math.ceil(len(B) / len(A))
    s = A * n

    if B in s:
      return n
    if B in s + A:
      return n + 1
    return -1
