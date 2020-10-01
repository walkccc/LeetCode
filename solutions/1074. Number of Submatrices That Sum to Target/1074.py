class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m = len(matrix)
        n = len(matrix[0])

        ans = 0

        for row in matrix:
            for j in range(1, n):
                row[j] += row[j - 1]

        for col in range(n):
            for j in range(col, n):
                count = {0: 1}
                sum = 0
                for i in range(m):
                    sum += matrix[i][j] - \
                        (matrix[i][col - 1] if col > 0 else 0)
                    ans += count.get(sum - target, 0)
                    count[sum] = count.get(sum, 0) + 1

        return ans
