class Solution:
  def trap(self, height: List[int]) -> int:
    if not height:
      return 0

    ans = 0
    l = 0
    r = len(height) - 1
    maxL = height[l]
    maxR = height[r]

    while l < r:
      if maxL < maxR:
        ans += maxL - height[l]
        l += 1
        maxL = max(maxL, height[l])
      else:
        ans += maxR - height[r]
        r -= 1
        maxR = max(maxR, height[r])

    return ans
