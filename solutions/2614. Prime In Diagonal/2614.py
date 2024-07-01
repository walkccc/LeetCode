class Solution:
  def diagonalPrime(self, nums: List[List[int]]) -> int:
    def isPrime(n: int) -> bool:
      if n <= 1:
        return False
      for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
          return False
      return True

    primes1 = [row[i]
               for i, row in enumerate(nums) if isPrime(row[i])]
    primes2 = [row[-i - 1]
               for i, row in enumerate(nums) if isPrime(row[-i - 1])]
    return max(max(primes1) if primes1 else 0,
               max(primes2) if primes2 else 0)
