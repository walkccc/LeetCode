class Solution:
  def distinctPrimeFactors(self, nums: list[int]) -> int:
    primes = set()

    for num in nums:
      self._addPrimeFactors(primes, num)

    return len(primes)

  def _addPrimeFactors(self, primes: set[int], num: int) -> None:
    for divisor in range(2, num + 1):
      if num % divisor == 0:
        primes.add(divisor)
        while num % divisor == 0:
          num //= divisor
