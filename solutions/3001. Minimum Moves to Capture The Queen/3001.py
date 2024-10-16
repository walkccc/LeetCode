class Solution:
  def minMovesToCaptureTheQueen(
      self, a: int, b: int, c: int, d: int, e: int, f: int,
  ) -> int:
    # The rook is in the same row as the queen.
    if a == e:
      # The bishop blocks the rook or not.
      return 2 if c == a and (b < d < f or b > d > f) else 1
    # The rook is in the same column as the queen.
    if b == f:
      # The bishop blocks the rook or not.
      return 2 if d == f and (a < c < e or a > c > e) else 1
    # The bishop is in the same up-diagonal as the queen.
    if c + d == e + f:
      # The rook blocks the bishop or not.
      return 2 if a + b == c + d and (c < a < e or c > a > e) else 1
    # The bishop is in the same down-diagonal as the queen.
    if c - d == e - f:
      # The rook blocks the bishop or not.
      return 2 if a - b == c - d and (c < a < e or c > a > e) else 1
    # The rook can always get the green in two steps.
    return 2
