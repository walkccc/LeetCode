class Solution:
  def baseNeg2(self, n: int) -> str:
    ans = []

    while n != 0:
      ans.append(str(n % 2))
      n = -(n >> 1)

    return ''.join(reversed(ans)) if ans else '0'
