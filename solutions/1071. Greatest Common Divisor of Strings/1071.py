class Solution:
  def gcdOfStrings(self, str1: str, str2: str) -> str:
    for sz in range(min(len(str1), len(str2)), 0, -1):
      if self._isDivisible(str1, str2, sz):
        return str1[:sz]
    return ''

  def _isDivisible(self, str1: str, str2: str, sz: int) -> bool:
    """Returns True if str1 and str2 are divisible by str1[0..sz)."""
    if len(str1) % sz > 0 or len(str2) % sz > 0:
      return False
    gcd = str1[:sz]
    return str1.replace(gcd, '') == '' and str2.replace(gcd, '') == ''
