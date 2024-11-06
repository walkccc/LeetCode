class Solution:
  def minimumString(self, a: str, b: str, c: str) -> str:
    def merge(a: str, b: str) -> str:
      """Merges a and b."""
      if a in b:  # a is a substring of b.
        return b
      for i in range(len(a)):
        aSuffix = a[i:]
        bPrefix = b[:len(aSuffix)]
        if aSuffix == bPrefix:
          return a + b[len(bPrefix):]
      return a + b

    abc = merge(a, merge(b, c))
    acb = merge(a, merge(c, b))
    bac = merge(b, merge(a, c))
    bca = merge(b, merge(c, a))
    cab = merge(c, merge(a, b))
    cba = merge(c, merge(b, a))
    return self._getMin([abc, acb, bac, bca, cab, cba])

  def _getMin(self, words: list[str]) -> str:
    """Returns the lexicographically smallest string."""

    def getMin(a: str, b: str) -> str:
      """Returns the lexicographically smaller string."""
      return a if len(a) < len(b) or (len(a) == len(b) and a < b) else b

    res = words[0]
    for i in range(1, len(words)):
      res = getMin(res, words[i])
    return res
