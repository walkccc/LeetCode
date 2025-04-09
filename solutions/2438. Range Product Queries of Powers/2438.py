class Solution:
  def productQueries(self, n: int, queries: list[list[int]]) -> list[int]:
    MOD = 1_000_000_007
    MAX_BIT = 30
    ans = []
    powers = [1 << i for i in range(MAX_BIT) if n >> i & 1]

    for left, right in queries:
      prod = 1
      for i in range(left, right + 1):
        prod *= powers[i]
        prod %= MOD
      ans.append(prod)

    return ans
