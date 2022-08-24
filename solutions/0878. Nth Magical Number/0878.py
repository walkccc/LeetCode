class Solution:
  def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
    lcm = a * b // math.gcd(a, b)
    l = min(a, b)
    r = min(a, b) * n

    while l < r:
      m = (l + r) // 2
      if m // a + m // b - m // lcm >= n:
        r = m
      else:
        l = m + 1

    return l % (10**9 + 7)
