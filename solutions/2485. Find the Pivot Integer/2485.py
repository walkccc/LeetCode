class Solution:
  def pivotInteger(self, n: int) -> int:
    # 1 + 2 + ... + x = x + ... + n
    # (1 + x) * x // 2 = (x + n) * (n - x + 1) // 2
    #         x + x^2 = nx - x^2 + x + n^2 - nx + n
    #         2 * x^2 = n^2 + n
    #               x = sqrt((n^2 + n) // 2)
    y = (n * n + n) // 2
    x = math.isqrt(y)
    return x if x * x == y else -1
