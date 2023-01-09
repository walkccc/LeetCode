class Solution:
  def baseNeg2(self, N: int) -> str:
    ans = ''

    while N:
      ans = str(N & 1) + ans
      N = -(N >> 1)

    return '0' if ans == '' else ans
