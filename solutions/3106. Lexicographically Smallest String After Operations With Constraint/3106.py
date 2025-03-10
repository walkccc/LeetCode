class Solution:
  def getSmallestString(self, s: str, k: int) -> str:
    ans = list(s)

    for i, c in enumerate(s):
      if k == 0:
        break
      distToA = min(ord(c) - ord('a'), ord('z') - ord(c) + 1)
      if k >= distToA:
        k -= distToA
        ans[i] = 'a'
      else:
        # k is not enough to change the current letter to 'a', so move as closer
        # to 'a' as possible.
        ans[i] = chr(ord(c) - k)
        k = 0

    return ''.join(ans)
