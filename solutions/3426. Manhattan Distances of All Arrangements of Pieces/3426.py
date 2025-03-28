class Solution:
  def distanceSum(self, m: int, n: int, k: int) -> int:
    # For each distance d, where 1 < d < m, there are `m - d` ways to choose
    # the two columns that the two pieces are on. For each of the two pieces,
    # there are `n` ways to choose the row that the piece is on.
    # Therefore, the contribution of row differences is
    #   sum(d * (m - d) * n^2), where 1 < d <= m - 1
    # = n^2 * sum(d * m - d^2)
    # = n^2 * (d * m * (m - 1) / 2 - m * (m - 1) * (2m - 1) / 6)
    # = n^2 * (m^3 - m) / 6
    # Similarly, the contribution of column differences is
    #   m^2 * (n^3 - n) / 6
    MOD = 1_000_000_007
    return (n**2 * (m**3 - m) // 6 +
            m**2 * (n**3 - n) // 6) * math.comb(m * n - 2, k - 2) % MOD
