class Solution:
  def isThree(self, n: int) -> bool:
    if n == 1:
      return False
    # The numbers with exactly three divisors are perfect squares of a prime
    # number.
    root = int(math.sqrt(n))
    return root**2 == n and \
        all(root % i != 0
            for i in range(2, int(math.sqrt(root)) + 1))
