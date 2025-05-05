class Solution:
  def generateString(self, str1: str, str2: str) -> str:
    n = len(str1)
    m = len(str2)
    sz = n + m - 1
    ans = [None] * sz
    modifiable = [True] * sz

    # 1. Handle all 'T' positions first.
    for i, tf in enumerate(str1):
      if tf == 'T':
        for j, c in enumerate(str2):
          pos = i + j
          if ans[pos] and ans[pos] != c:
            return ''
          ans[pos] = c
          modifiable[pos] = False

    # 2. Fill all remaining positions with 'a'.
    for i in range(sz):
      if not ans[i]:
        ans[i] = 'a'

    # 3. Handle all 'F' positions.
    for i in range(n):
      if str1[i] == 'F' and self._match(ans, i, str2):
        modifiablePos = self._lastModifiablePosition(i, m, modifiable)
        if modifiablePos == -1:
          return ''
        ans[modifiablePos] = 'b'
        modifiable[modifiablePos] = False

    return ''.join(ans)

  def _match(self, ans: list, i: int, s: str) -> bool:
    """Returns True if the substring of ans starting at `i` matches `s`."""
    for j, c in enumerate(s):
      if ans[i + j] != c:
        return False
    return True

  def _lastModifiablePosition(self, i: int, m: int, modifiable: list) -> int:
    """
    Finds the last modifiable position in the substring of ans starting at `i`.
    """
    modifiablePos = -1
    for j in range(m):
      pos = i + j
      if modifiable[pos]:
        modifiablePos = pos
    return modifiablePos
