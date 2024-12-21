class Solution:
  def monkeyMove(self, n: int) -> int:
    kMod = 1_000_000_007
    res = pow(2, n, kMod) - 2
    return res + kMod if res < 0 else res
