class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        ans = []
        r1 = 0
        c1 = 0
        r2 = len(matrix) - 1
        c2 = len(matrix[0]) - 1

        while r1 <= r2 and c1 <= c2:
            for c in range(c1, c2 + 1):
                ans.append(matrix[r1][c])
            for r in range(r1 + 1, r2 + 1):
                ans.append(matrix[r][c2])
            if r1 < r2 and c1 < c2:
                for c in range(c2 - 1, c1, -1):
                    ans.append(matrix[r2][c])
                for r in range(r2, r1, -1):
                    ans.append(matrix[r][c1])
            r1 += 1
            c1 += 1
            r2 -= 1
            c2 -= 1

        return ans
