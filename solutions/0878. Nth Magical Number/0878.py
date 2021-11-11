class Solution:
  def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
    lcm = A * B // math.gcd(A, B)
    l = min(A, B)
    r = min(A, B) * N

    while l < r:
      m = (l + r) // 2
      if m // A + m // B - m // lcm >= N:
        r = m
      else:
        l = m + 1

    return l % (10**9 + 7)
