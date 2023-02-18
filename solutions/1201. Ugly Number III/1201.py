class Solution:
  def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
    ab = a * b // math.gcd(a, b)
    ac = a * c // math.gcd(a, c)
    bc = b * c // math.gcd(b, c)
    abc = a * bc // math.gcd(a, bc)

    l = 1
    r = 2 * int(1e9)

    while l < r:
      m = (l + r) // 2
      if m // a + m // b + m // c - m // ab - m // ac - m // bc + m // abc >= n:
        r = m
      else:
        l = m + 1

    return l
