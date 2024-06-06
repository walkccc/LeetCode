class Solution:
  def minimumMoves(self, s: str) -> int:
    ans = 0

    i = 0
    while i < len(s):
      if s[i] == 'O':
        i += 1
      else:
        ans += 1
        i += 3

    return ans
