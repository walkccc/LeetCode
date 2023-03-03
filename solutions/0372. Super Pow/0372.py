class Solution:
  def superPow(self, a: int, b: List[int]) -> int:
    def powMod(x: int, y: int) -> int:
      pow = 1
      for _ in range(y):
        pow = (pow * x) % k
      return pow

    k = 1337
    ans = 1

    for i in b:
      ans = powMod(ans, 10) * powMod(a, i) % k

    return ans
