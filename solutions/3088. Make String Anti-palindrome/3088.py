class Solution:
  def makeAntiPalindrome(self, s: str) -> str:
    n = len(s)
    i = n // 2
    chars = sorted(list(s))
    if chars[i] != chars[n - i - 1]:
      return ''.join(chars)

    j = self._getFirstDiffIndexInSecondHalf(chars)
    while chars[i] == chars[n - i - 1]:
      if j == n:
        return '-1'
      chars[i], chars[j] = chars[j], chars[i]
      i += 1
      j += 1

    return ''.join(chars)

  def _getFirstDiffIndexInSecondHalf(self, chars: list[str]) -> int:
    """
    Returns the first index in chars[n / 2..n) that is different from the first
    letter of the second half, chars[n / 2].
    """
    n = len(chars)
    firstLetter = chars[n // 2]
    firstDiffIndex = n // 2
    while firstDiffIndex < n and chars[firstDiffIndex] == firstLetter:
      firstDiffIndex += 1
    return firstDiffIndex
