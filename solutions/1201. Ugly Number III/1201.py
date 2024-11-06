class Solution:
  def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
    ab = a * b // math.gcd(a, b)
    ac = a * c // math.gcd(a, c)
    bc = b * c // math.gcd(b, c)
    abc = a * bc // math.gcd(a, bc)
    return bisect.bisect_left(
        range(2 * 10 ** 9),
        n, key=lambda m: m // a + m // b + m // c - m // ab -
        m // ac - m // bc + m // abc)
