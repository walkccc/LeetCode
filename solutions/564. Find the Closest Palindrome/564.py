class Solution:
  def nearestPalindromic(self, n: str) -> str:
    prevPalindrome, nextPalindrome = self._getPalindromes(n)
    return (str(prevPalindrome)
            if abs(prevPalindrome - int(n)) <= abs(nextPalindrome - int(n))
            else str(nextPalindrome))

  def _getPalindromes(self, s: str) -> tuple[str, str]:
    """Returns the two closest palindromes to the given number."""
    num = int(s)
    sz = len(s)
    palindromes = []
    half = s[0:(sz + 1) // 2]
    reversedHalf = half[:sz // 2][::-1]
    candidate = int(half + reversedHalf)

    if candidate < num:
      palindromes.append(candidate)
    else:
      prevHalf = str(int(half) - 1)
      reversedPrevHalf = prevHalf[:sz // 2][::-1]
      if sz % 2 == 0 and int(prevHalf) == 0:
        palindromes.append(9)
      elif sz % 2 == 0 and prevHalf == '9':
        palindromes.append(int(prevHalf + '9' + reversedPrevHalf))
      else:
        palindromes.append(int(prevHalf + reversedPrevHalf))

    if candidate > num:
      palindromes.append(candidate)
    else:
      nextHalf = str(int(half) + 1)
      reversedNextHalf = nextHalf[:sz // 2][::-1]
      palindromes.append(int(nextHalf + reversedNextHalf))

    return palindromes
