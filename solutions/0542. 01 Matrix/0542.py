class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        dirs = [0, 1, 0, -1, 0]
        queue = collections.deque()

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    queue.append([i, j])
                else:
                    matrix[i][j] = float('inf')

        while queue:
            i, j = queue.popleft()
            for k in range(4):
                x = i + dirs[k]
                y = j + dirs[k + 1]
                if x < 0 or x >= len(matrix) or y < 0 or y >= len(matrix[0]) or matrix[x][y] <= matrix[i][j] + 1:
                    continue
                queue.append([x, y])
                matrix[x][y] = matrix[i][j] + 1

        return matrix
