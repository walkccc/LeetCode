class Solution:
  def smallestValue(self, n: int) -> int:
    def getPrimeSum(n: int) -> int:
      primeSum = 0
      for i in range(2, n + 1):
        while n % i == 0:
          n //= i
          primeSum += i
      return primeSum

    primeSum = getPrimeSum(n)
    while n != primeSum:
      n = primeSum
      primeSum = getPrimeSum(n)
    return n
