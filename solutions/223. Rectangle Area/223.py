class Solution:
  def computeArea(self,
                  A: int, B: int, C: int, D: int,
                  E: int, F: int, G: int, H: int) -> int:
    x = min(C, G) - max(A, E) if max(A, E) < min(C, G) else 0
    y = min(D, H) - max(B, F) if max(B, F) < min(D, H) else 0
    return (C - A) * (D - B) + (G - E) * (H - F) - x * y
