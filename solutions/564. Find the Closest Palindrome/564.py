class Solution:
  def nearestPalindromic(self, n: str) -> str:
    def getPalindromes(s: str) -> tuple:
      num = int(s)
      k = len(s)
      palindromes = []
      half = s[0:(k + 1) // 2]
      reversedHalf = half[:k // 2][::-1]
      candidate = int(half + reversedHalf)

      if candidate < num:
        palindromes.append(candidate)
      else:
        prevHalf = str(int(half) - 1)
        reversedPrevHalf = prevHalf[:k // 2][::-1]
        if k % 2 == 0 and int(prevHalf) == 0:
          palindromes.append(9)
        elif k % 2 == 0 and (int(prevHalf) + 1) % 10 == 0:
          palindromes.append(int(prevHalf + '9' + reversedPrevHalf))
        else:
          palindromes.append(int(prevHalf + reversedPrevHalf))

      if candidate > num:
        palindromes.append(candidate)
      else:
        nextHalf = str(int(half) + 1)
        reversedNextHalf = nextHalf[:k // 2][::-1]
        palindromes.append(int(nextHalf + reversedNextHalf))

      return palindromes

    prevPalindrome, nextPalindrome = getPalindromes(n)
    return str(prevPalindrome) if abs(prevPalindrome - int(n)) <= abs(nextPalindrome - int(n)) else str(nextPalindrome)
