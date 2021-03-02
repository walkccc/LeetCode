class Solution:
  def countOrders(self, n: int) -> int:
    kMod = int(1e9 + 7)

    ans = 1

    for i in range(1, n + 1):
      ans = ans * i * (i * 2 - 1) % kMod

    return ans
