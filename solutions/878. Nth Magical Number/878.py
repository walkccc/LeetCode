class Solution:
  def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
    lcm = a * b // math.gcd(a, b)
    l = min(a, b)
    r = min(a, b) * n
    ans = bisect.bisect_left(range(l, r), n,
                             key=lambda m: m // a + m // b - m // lcm) + l
    return ans % (10**9 + 7)
