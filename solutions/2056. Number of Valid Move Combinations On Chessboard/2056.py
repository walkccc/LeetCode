class Solution:
  def countCombinations(
      self,
      pieces: list[str],
      positions: list[list[int]],
  ) -> int:
    n = len(pieces)
    moves = {"rook": [(1, 0), (-1, 0), (0, 1), (0, -1)],
             "bishop": [(1, 1), (1, -1), (-1, 1), (-1, -1)],
             "queen": [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]}
    hashedBoards = set()

    def getHash(board: list[list[int]]) -> Tuple:
      return tuple([tuple(pos) for pos in board])

    def dfs(
        board: list[list[int]],
        pieceMoves: list[tuple[int, int]],
        activeMask: int,
    ) -> None:
      """Performs a depth-first search to explore all possible board states."""
      if activeMask == 0:
        return
      hashedBoards.add(getHash(board))

      for nextActiveMask in range(1, 1 << n):
        if activeMask & nextActiveMask != nextActiveMask:
          continue

        # Copy the board.
        nextBoard = [pos.copy() for pos in board]

        # Move the pieces that are active in this turn.
        for i in range(n):
          if nextActiveMask >> i & 1:
            nextBoard[i][0] += pieceMoves[i][0]
            nextBoard[i][1] += pieceMoves[i][1]

        # No two or more pieces occupy the same square.
        if len(set(getHash(nextBoard))) < n:
          continue

        # Every piece needs to be in the boundary.
        if all(1 <= x <= 8 and 1 <= y <= 8 for x, y in nextBoard):
          dfs(nextBoard, pieceMoves, nextActiveMask)

    for pieceMoves in itertools.product(*(moves[piece] for piece in pieces)):
      dfs(positions, pieceMoves, (1 << n) - 1)

    return len(hashedBoards)
