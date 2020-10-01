class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans = 0
        stack = []

        for i in range(len(heights) + 1):
            while stack != [] and (i == len(heights) or heights[i] < heights[stack[-1]]):
                h = heights[stack.pop()]
                w = i if stack == [] else i - stack[-1] - 1
                ans = max(ans, h * w)
            stack.append(i)

        return ans
