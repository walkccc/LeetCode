class Solution:
  def findBuildings(self, heights: list[int]) -> list[int]:
    stack = []

    for i, height in enumerate(heights):
      while stack and heights[stack[-1]] <= height:
        stack.pop()
      stack.append(i)

    return stack
