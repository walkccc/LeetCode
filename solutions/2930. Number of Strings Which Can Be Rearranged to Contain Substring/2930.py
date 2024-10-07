class Solution:
  def stringCount(self, n: int) -> int:
    # There're three invalid conditions:
    #   a. count('l') == 0
    #   b. count('e') < 2
    #   c. count('t') == 0
    #
    # By Principle of Inclusion-Exclusion (PIE):
    #   ans = allCount - a - b - c + ab + ac + bc - abc
    kMod = 1_000_000_007
    allCount = pow(26, n, kMod)
    a = pow(25, n, kMod)
    b = pow(25, n, kMod)
    c = pow(25, n, kMod) + n * pow(25, n - 1, kMod)
    ab = pow(24, n, kMod) + n * pow(24, n - 1, kMod)
    ac = pow(24, n, kMod)
    bc = pow(24, n, kMod) + n * pow(24, n - 1, kMod)
    abc = pow(23, n, kMod) + n * pow(23, n - 1, kMod)
    return (allCount - a - b - c + ab + ac + bc - abc) % kMod
