class Solution:
  def matchReplacement(
      self,
      s: str,
      sub: str,
      mappings: list[list[str]],
  ) -> bool:
    isMapped = [[False] * 128 for _ in range(128)]

    for old, new in mappings:
      isMapped[ord(old)][ord(new)] = True

    for i in range(len(s)):
      if self._canTransform(s, i, sub, isMapped):
        return True

    return False

  def _canTransform(
      self,
      s: str,
      start: int,
      sub: str,
      isMapped: list[list[bool]],
  ) -> bool:
    if start + len(sub) > len(s):
      return False

    for i in range(len(sub)):
      a = sub[i]
      b = s[start + i]
      if a != b and not isMapped[ord(a)][ord(b)]:
        return False

    return True
