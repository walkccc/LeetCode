class Solution:
  def __init__(self):
    self.MAX = 10**6 + 1

  def smallestPalindrome(self, s: str, k: int) -> str:
    count = collections.Counter(s)
    if not self._isPalindromePossible(count):
      return ''

    halfCount, midLetter = self._getHalfCountAndMidLetter(count)
    totalPerm = self._calculateTotalPermutations(halfCount)
    if k > totalPerm:
      return ''
    leftHalf = self._generateLeftHalf(halfCount, k)
    return ''.join(leftHalf) + midLetter + ''.join(reversed(leftHalf))

  def _isPalindromePossible(self, count: collections.Counter) -> bool:
    oddCount = sum(1 for count in count.values() if count % 2 == 1)
    return oddCount <= 1

  def _getHalfCountAndMidLetter(self, count: collections.Counter) -> tuple[list[int], str]:
    halfCount = [0] * 26
    midLetter = ''
    for c, freq in count.items():
      halfCount[ord(c) - ord('a')] = freq // 2
      if freq % 2 == 1:
        midLetter = c
    return halfCount, midLetter

  def _calculateTotalPermutations(self, halfCount: list[int]) -> int:
    """Calculate the total number of possible permutations."""
    return self._countArrangements(halfCount)

  def _generateLeftHalf(self, halfCount: list[int], k: int) -> list[str]:
    """Generate the left half of the palindrome based on k."""
    halfLen = sum(halfCount)
    left = []
    for _ in range(halfLen):
      for i, freq in enumerate(halfCount):
        if freq == 0:
          continue
        halfCount[i] -= 1
        arrangements = self._countArrangements(halfCount)
        if arrangements >= k:
          left.append(chr(i + ord('a')))
          break
        else:
          k -= arrangements
          halfCount[i] += 1
    return left

  def _countArrangements(self, count: list[int]) -> int:
    """Calculate the number of possible arrangements of characters."""
    total = sum(count)
    res = 1
    for freq in count:
      res *= self._nCk(total, freq)
      if res >= self.MAX:
        return self.MAX
      total -= freq
    return res

  def _nCk(self, n: int, k: int) -> int:
    res = 1
    for i in range(1, min(k, n - k) + 1):
      res = res * (n - i + 1) // i
      if res >= self.MAX:
        return self.MAX
    return res
