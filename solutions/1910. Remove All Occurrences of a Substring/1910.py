class Solution:
  def removeOccurrences(self, s: str, part: str) -> str:
    n = len(s)
    k = len(part)

    t = [' '] * n
    j = 0  # t's index

    for i, c in enumerate(s):
      t[j] = c
      j += 1
      if j >= k and ''.join(t[j - k:j]) == part:
        j -= k

    return ''.join(t[:j])
