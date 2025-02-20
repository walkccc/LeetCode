class Solution:
  def superPow(self, a: int, b: list[int]) -> int:
    kMod = 1337
    ans = 1

    for i in b:
      ans = pow(ans, 10, kMod) * pow(a, i, kMod)

    return ans % kMod
