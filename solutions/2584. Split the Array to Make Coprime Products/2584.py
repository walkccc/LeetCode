class Solution:
  def findValidSplit(self, nums: list[int]) -> int:
    leftPrimeFactors = collections.Counter()
    rightPrimeFactors = collections.Counter()

    def getPrimeFactors(num: int) -> list[int]:
      """Gets the prime factors under sqrt(10^6)."""
      primeFactors = []
      for divisor in range(2, min(1000, num) + 1):
        if num % divisor == 0:
          primeFactors.append(divisor)
          while num % divisor == 0:
            num //= divisor
      # Handle the case that `num` contains a prime factor > 1000.
      if num > 1:
        primeFactors.append(num)
      return primeFactors

    for num in nums:
      for primeFactor in getPrimeFactors(num):
        rightPrimeFactors[primeFactor] += 1

    for i in range(len(nums) - 1):
      for primeFactor in getPrimeFactors(nums[i]):
        rightPrimeFactors[primeFactor] -= 1
        if rightPrimeFactors[primeFactor] == 0:
          # rightPrimeFactors[primeFactor] == 0, so no need to track
          # leftPrimeFactors[primeFactor].
          del rightPrimeFactors[primeFactor]
          del leftPrimeFactors[primeFactor]
        else:
          # Otherwise, need to track leftPrimeFactors[primeFactor].
          leftPrimeFactors[primeFactor] += 1
      if not leftPrimeFactors:
        return i

    return -1
