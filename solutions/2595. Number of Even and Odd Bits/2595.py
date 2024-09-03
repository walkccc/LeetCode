class Solution:
  def evenOddBit(self, n: int) -> list[int]:
    ans = [0] * 2
    i = 0  # 0 := even, 1 := odd

    while n > 0:
      ans[i] += n & 1
      n >>= 1
      i ^= 1

    return ans
