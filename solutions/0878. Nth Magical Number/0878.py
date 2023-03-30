class Solution:
  def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
    lcm = a * b // math.gcd(a, b)
    l = bisect.bisect_left(range(min(a, b), min(a, b) * n), n,
                           key=lambda m: m // a + m // b - m // lcm) + min(a, b)
    return l % (10**9 + 7)
