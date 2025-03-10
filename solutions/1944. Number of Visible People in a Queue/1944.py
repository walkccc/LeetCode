class Solution:
  def canSeePersonsCount(self, heights: list[int]) -> list[int]:
    ans = [0] * len(heights)
    stack = []

    for i, height in enumerate(heights):
      while stack and heights[stack[-1]] <= height:
        ans[stack.pop()] += 1
      if stack:
        ans[stack[-1]] += 1
      stack.append(i)

    return ans
