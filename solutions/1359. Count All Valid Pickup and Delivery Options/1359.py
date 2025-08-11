class Solution:
  def countOrders(self, n: int) -> int:
    MOD = 1_000_000_007
    ans = 1

    for i in range(1, n + 1):
      ans = ans * i * (i * 2 - 1) % MOD

    return ans
