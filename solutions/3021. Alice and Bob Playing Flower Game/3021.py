class Solution:
  def flowerGame(self, n: int, m: int) -> int:
    # Alice wins if x + y is odd, occurring when:
    #   1. x is even and y is odd, or
    #   2. y is even and x is odd.
    xEven = n // 2
    yEven = m // 2
    xOdd = (n + 1) // 2
    yOdd = (m + 1) // 2
    return xEven * yOdd + yEven * xOdd
