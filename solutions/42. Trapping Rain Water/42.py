class Solution:
  def trap(self, height: List[int]) -> int:
    n = len(height)
    l = [0] * n  # l[i] := max(height[0..i])
    r = [0] * n  # r[i] := max(height[i..n))

    for i, h in enumerate(height):
      l[i] = h if i == 0 else max(h, l[i - 1])

    for i, h in reversed(list(enumerate(height))):
      r[i] = h if i == n - 1 else max(h, r[i + 1])

    return sum(min(l[i], r[i]) - h
               for i, h in enumerate(height))
