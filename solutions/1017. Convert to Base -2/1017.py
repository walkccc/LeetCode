class Solution:
  def baseNeg2(self, n: int) -> str:
    ans = []

    while n != 0:
      ans.append(str(n & 1))
      n = -(n >> 1)

    return ''.join(ans[::-1]) if ans else '0'
