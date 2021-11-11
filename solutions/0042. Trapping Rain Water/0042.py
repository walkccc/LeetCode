class Solution:
  def trap(self, height: List[int]) -> int:
    n = len(height)

    ans = 0
    l = [0] * n  # l[i] := max(height[0..i])
    r = [0] * n  # r[i] := max(height[i..n))

    for i in range(n):
      l[i] = height[i] if i == 0 else max(height[i], l[i - 1])

    for i in range(n - 1, -1, -1):
      r[i] = height[i] if i == n - 1 else max(height[i], r[i + 1])

    for i in range(n):
      ans += min(l[i], r[i]) - height[i]

    return ans
