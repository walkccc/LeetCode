class Solution:
  def countGoodIntegers(self, n: int, k: int) -> int:
    halfLength = (n + 1) // 2
    minHalf = 10**(halfLength - 1)
    maxHalf = 10**halfLength
    ans = 0
    seen = set()

    for num in range(minHalf, maxHalf):
      palindrome = str(num) + str(num)[::-1][n % 2:]
      sortedDigits = ''.join(sorted(palindrome))
      if int(palindrome) % k != 0 or sortedDigits in seen:
        continue
      seen.add(sortedDigits)
      digitCount = collections.Counter(palindrome)
      # Leading zeros are not allowed, so the first digit is special.
      firstDigitChoices = n - digitCount['0']
      permutations = firstDigitChoices * math.factorial(n - 1)
      # For each repeated digit, divide by the factorial of the frequency since
      # permutations that swap identical digits don't create a new number.
      for freq in digitCount.values():
        permutations //= math.factorial(freq)
      ans += permutations

    return ans
