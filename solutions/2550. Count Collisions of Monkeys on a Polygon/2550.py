class Solution:
  def monkeyMove(self, n: int) -> int:
    MOD = 1_000_000_007
    res = pow(2, n, MOD) - 2
    return res + MOD if res < 0 else res
