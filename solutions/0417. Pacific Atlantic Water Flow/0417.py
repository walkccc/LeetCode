class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        def bfs(q: collections.deque, seen: List[List[bool]]):
            while q:
                [i, j] = q.popleft()
                h = matrix[i][j]
                seen[i][j] = True
                for k in range(4):
                    x = i + dirs[k]
                    y = j + dirs[k + 1]
                    if not 0 <= x < m or not 0 <= y < n or matrix[x][y] < h or seen[x][y]:
                        continue
                    q.append((x, y))

        if not matrix:
            return []

        m = len(matrix)
        n = len(matrix[0])
        dirs = [0, 1, 0, -1, 0]

        qP = collections.deque()
        qA = collections.deque()
        seenP = [[False] * n for _ in range(m)]
        seenA = [[False] * n for _ in range(m)]

        for i in range(m):
            qP.append((i, 0))
            qA.append((i, n - 1))

        for j in range(n):
            qP.append((0, j))
            qA.append((m - 1, j))

        bfs(qP, seenP)
        bfs(qA, seenA)

        return [[i, j] for i in range(m) for j in range(n) if seenP[i][j] and seenA[i][j]]
