class Solution:
  def maximalRectangle(self, matrix: list[list[str]]) -> int:
    if not matrix:
      return 0

    ans = 0
    hist = [0] * len(matrix[0])

    def largestRectangleArea(heights: list[int]) -> int:
      ans = 0
      stack = []

      for i in range(len(heights) + 1):
        while stack and (i == len(heights) or heights[stack[-1]] > heights[i]):
          h = heights[stack.pop()]
          w = i - stack[-1] - 1 if stack else i
          ans = max(ans, h * w)
        stack.append(i)

      return ans

    for row in matrix:
      for i, num in enumerate(row):
        hist[i] = 0 if num == '0' else hist[i] + 1
      ans = max(ans, largestRectangleArea(hist))

    return ans
