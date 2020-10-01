class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m = len(matrix)
        n = len(matrix[0])

        isFirstRow = 0 in matrix[0]
        isFirstCol = 0 in list(zip(*matrix))[0]

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        if isFirstRow:
            matrix[0] = [0] * n

        if isFirstCol:
            for row in matrix:
                row[0] = 0
