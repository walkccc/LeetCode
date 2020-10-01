class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i: int, j: int, pos: int) -> bool:
            if not 0 <= i < len(board) or not 0 <= j < len(board[0]) or board[i][j] != word[pos] or board[i][j] == '*':
                return False
            if pos == len(word) - 1:
                return True

            c = board[i][j]
            board[i][j] = '*'
            flag = \
                dfs(i + 1, j, pos + 1) or \
                dfs(i - 1, j, pos + 1) or \
                dfs(i, j + 1, pos + 1) or \
                dfs(i, j - 1, pos + 1)
            board[i][j] = c

            return flag

        if not board:
            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0):
                    return True

        return False
