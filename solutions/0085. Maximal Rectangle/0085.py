class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        def largestRectangleArea(heights: List[int]) -> int:
            ans = 0
            stack = []

            for i in range(len(heights) + 1):
                while stack != [] and (i == len(heights) or heights[i] < heights[stack[-1]]):
                    h = heights[stack.pop()]
                    w = i if stack == [] else i - stack[-1] - 1
                    ans = max(ans, h * w)
                stack.append(i)

            return ans

        if matrix == []:
            return 0

        ans = 0
        temp = [0] * len(matrix[0])

        for row in matrix:
            for i, num in enumerate(row):
                temp[i] = 0 if num == '0' else temp[i] + 1
            ans = max(ans, largestRectangleArea(temp))

        return ans
