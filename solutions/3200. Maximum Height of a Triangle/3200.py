class Solution:
  def maxHeightOfTriangle(self, red: int, blue: int) -> int:
    return max(self._maxHeight(red, blue),
               self._maxHeight(blue, red))

  def _maxHeight(self, n1: int, n2: int) -> int:
    """
    Returns the maximum height of a triangle with the odd levels having `n1`
    balls and the even levels having `n2` balls.
    """
    #             1 + 3 + ... + h <= n1
    # ((1 + h) * (n + 1) / 2) / 2 <= n1
    #                           h <= sqrt(4 * n1) - 1
    oddHeight = math.isqrt(4 * n1) - 1
    #       2 + 4 + ... + h <= n2
    # ((2 + h) * h / 2) / 2 <= n2
    #                     h <= sqrt(4 * n2 + 1) - 1
    evenHeight = math.isqrt(4 * n2 + 1) - 1
    # If the difference between the odd and even heights is >= 1, we can add an
    # extra level to the minimum height.
    return min(oddHeight, evenHeight) + (1 if abs(oddHeight - evenHeight) >= 1
                                         else 0)
