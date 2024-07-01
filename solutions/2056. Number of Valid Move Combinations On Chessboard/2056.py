class Solution:
  def countCombinations(self, pieces: List[str], positions: List[List[int]]) -> int:
    n = len(pieces)
    moves = {"rook": [(1, 0), (-1, 0), (0, 1), (0, -1)],
             "bishop": [(1, 1), (1, -1), (-1, 1), (-1, -1)],
             "queen": [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]}
    ans = set()

    def getHash(board: List[List[int]]) -> Tuple:
      return tuple([tuple(pos) for pos in board])

    def dfs(board: List[List[int]], combMove: List[Tuple[int, int]], activeMask: int) -> None:
      if activeMask == 0:
        return
      ans.add(getHash(board))

      for nextActiveMask in range(1, 1 << n):
        if activeMask & nextActiveMask != nextActiveMask:
          continue

        # Make sure to copy the board.
        nextBoard = [pos.copy() for pos in board]

        # Move the pieces that are active in this turn.
        for i in range(n):
          if (nextActiveMask >> i) & 1:
            nextBoard[i][0] += combMove[i][0]
            nextBoard[i][1] += combMove[i][1]

        # No two or more pieces occupy the same square.
        if len(set(getHash(nextBoard))) < n:
          continue

        # Everything needs to be in the boundary.
        if all(1 <= x <= 8 and 1 <= y <= 8 for x, y in nextBoard):
          dfs(nextBoard, combMove, nextActiveMask)

    for combMove in product(*(moves[piece] for piece in pieces)):
      dfs(positions, combMove, (1 << n) - 1)

    return len(ans)
