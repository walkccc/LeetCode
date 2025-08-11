class Solution:
  def stringCount(self, n: int) -> int:
    # There're three invalid conditions:
    #   a. count('l') == 0
    #   b. count('e') < 2
    #   c. count('t') == 0
    #
    # By Principle of Inclusion-Exclusion (PIE):
    #   ans = allCount - a - b - c + ab + ac + bc - abc
    MOD = 1_000_000_007
    allCount = pow(26, n, MOD)
    a = pow(25, n, MOD)
    b = pow(25, n, MOD)
    c = pow(25, n, MOD) + n * pow(25, n - 1, MOD)
    ab = pow(24, n, MOD) + n * pow(24, n - 1, MOD)
    ac = pow(24, n, MOD)
    bc = pow(24, n, MOD) + n * pow(24, n - 1, MOD)
    abc = pow(23, n, MOD) + n * pow(23, n - 1, MOD)
    return (allCount - a - b - c + ab + ac + bc - abc) % MOD
