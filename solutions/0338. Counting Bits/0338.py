class Solution:
  def countBits(self, n: int) -> List[int]:
    # Let f(i) := i's # Of 1's in bitmask
    # f(i) = f(i / 2) + i % 2
    ans = [0] * (n + 1)

    for i in range(1, n + 1):
      ans[i] = ans[i // 2] + (i & 1)

    return ans
