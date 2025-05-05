class Solution:
  def bulbSwitch(self, n: int) -> int:
    # The k-th bulb can only be switched when k % i == 0.
    # So, we can rephrase the problem:
    # To find number of numbers <= n that have odd factors.
    # Obviously, only square numbers have odd factor(s).
    # e.g. n = 10, only 1, 4, and 9 are square numbers that <= 10
    return math.isqrt(n)
