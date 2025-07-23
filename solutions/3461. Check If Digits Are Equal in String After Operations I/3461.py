class Solution:
  def hasSameDigits(self, s: str) -> bool:
    n = len(s)
    num1 = 0
    num2 = 0

    for i in range(n - 1):
      coefficient = self._nCMOD10(n - 2, i)
      num1 += (coefficient * (int(s[i]) - 0)) % 10
      num1 %= 10
      num2 += (coefficient * (int(s[i + 1]) - 0)) % 10
      num2 %= 10

    return num1 == num2

  def _nCMOD10(self, n: int, k: int) -> int:
    """Returns (n, k) % 10."""
    mod2 = self._lucasTheorem(n, k, 2)
    mod5 = self._lucasTheorem(n, k, 5)
    lookup = [
        [0, 6, 2, 8, 4],  # mod2 == 0
        [5, 1, 7, 3, 9]   # mod2 == 1
    ]
    return lookup[mod2][mod5]

  def _lucasTheorem(self, n: int, k: int, prime: int) -> int:
    """Returns (n, k) % prime."""
    res = 1
    while n > 0 or k > 0:
      nMod = n % prime
      MOD = k % prime
      res *= math.comb(nMod, MOD)
      res %= prime
      n //= prime
      k //= prime
    return res
