class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        def dfs(i: int, j: int) -> None:
            if not 0 <= i < len(board) or not 0 <= j < len(board[0]) or board[i][j] != 'E':
                return

            minesCount = 0
            for dx, dy in dirs:
                x = i + dx
                y = j + dy
                if 0 <= x < len(board) and 0 <= y < len(board[0]) and board[x][y] == 'M':
                    minesCount += 1
            board[i][j] = str(minesCount) if minesCount > 0 else 'B'

            if minesCount == 0:
                for dx, dy in dirs:
                    dfs(i + dx, j + dy)

        if board[click[0]][click[1]] == 'M':
            board[click[0]][click[1]] = 'X'
            return board

        dirs = [(-1, -1), (-1, 0), (-1, 1), (0, -1),
                (0, 1), (1, -1), (1, 0), (1, 1)]

        dfs(click[0], click[1])

        return board
