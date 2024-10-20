class Solution:
  def valueAfterKSeconds(self, n: int, k: int) -> int:
    return math.comb(n + k - 1, n - 1) % 1_000_000_007
