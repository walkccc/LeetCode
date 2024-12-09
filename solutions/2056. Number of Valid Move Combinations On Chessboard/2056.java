class Solution {
  public int countCombinations(String[] pieces, int[][] positions) {
    final int n = pieces.length;
    Set<Long> hashedBoards = new HashSet<>();
    // Stores all possible move combinations for `pieces`. Each element is a
    // vector of moves, one for each piece in the input order. e.g., if pieces =
    // ["rook", "bishop"], one element might be [[1,0], [1,1]], representing a
    // rook moving right and a bishop moving diagonally up-right.
    List<List<int[]>> combMoves = new ArrayList<>();

    getCombMoves(pieces, 0, new ArrayList<>(), combMoves);

    for (List<int[]> combMove : combMoves)
      dfs(positions, n, combMove, (1 << n) - 1, hashedBoards);

    return hashedBoards.size();
  }

  private static Map<String, int[][]> kMoves = new HashMap<>();

  static {
    kMoves.put("rook", new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
    kMoves.put("bishop", new int[][] {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}});
    kMoves.put("queen",
               new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}});
  }

  // Generates all possible combinations of moves for the given pieces.
  private void getCombMoves(String[] pieces, int ithPiece, List<int[]> path,
                            List<List<int[]>> combMoves) {
    if (ithPiece == pieces.length) {
      combMoves.add(new ArrayList<>(path));
      return;
    }

    for (int[] move : kMoves.get(pieces[ithPiece])) {
      path.add(move);
      getCombMoves(pieces, ithPiece + 1, path, combMoves);
      path.remove(path.size() - 1);
    }
  }

  // Performs a depth-first search to explore all possible board states.
  private void dfs(int[][] board, int n, List<int[]> combMove, int activeMask,
                   Set<Long> hashedBoards) {
    if (activeMask == 0)
      return;
    hashedBoards.add(getHash(board));

    for (int nextActiveMask = 1; nextActiveMask < 1 << n; ++nextActiveMask) {
      if ((activeMask & nextActiveMask) != nextActiveMask)
        continue;

      // Copy the board.
      int[][] nextBoard = new int[n][];
      for (int i = 0; i < n; ++i)
        nextBoard[i] = board[i].clone();

      // Move the pieces that are active in this turn.
      for (int i = 0; i < n; ++i)
        if ((nextActiveMask >> i & 1) == 1) {
          nextBoard[i][0] += combMove.get(i)[0];
          nextBoard[i][1] += combMove.get(i)[1];
        }

      // No two or more pieces occupy the same square.
      if (getUniqueSize(nextBoard) < n)
        continue;

      // Every piece needs to be in the boundary.
      if (Arrays.stream(nextBoard).allMatch(p -> 1 <= p[0] && p[0] <= 8 && 1 <= p[1] && p[1] <= 8))
        dfs(nextBoard, n, combMove, nextActiveMask, hashedBoards);
    }
  }

  // Generates a unique hash for the given board state.
  private long getHash(int[][] board) {
    long hash = 0;
    for (int[] pos : board)
      hash = (hash * 64) + (pos[0] - 1 << 3) + (pos[1] - 1);
    return hash;
  }

  // Counts the number of unique positions on the board occupied by the pieces.
  private int getUniqueSize(int[][] board) {
    Set<Integer> unique = new HashSet<>();
    for (int[] pos : board)
      unique.add(pos[0] * 8 + pos[1]);
    return unique.size();
  }
}
