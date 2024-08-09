class Solution:
  def largestRectangleArea(self, heights: List[int]) -> int:
    ans = 0
    stack = []

    for i in range(len(heights) + 1):
      while stack and (i == len(heights) or heights[stack[-1]] > heights[i]):
        h = heights[stack.pop()]
        w = i - stack[-1] - 1 if stack else i
        ans = max(ans, h * w)
      stack.append(i)

    return ans
