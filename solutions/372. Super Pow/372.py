class Solution:
  def superPow(self, a: int, b: list[int]) -> int:
    MOD = 1337
    ans = 1

    for i in b:
      ans = pow(ans, 10, MOD) * pow(a, i, MOD)

    return ans % MOD
