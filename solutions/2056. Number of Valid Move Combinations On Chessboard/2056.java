class Solution {
  public int countCombinations(String[] pieces, int[][] positions) {
    final int n = pieces.length;
    Set<Long> ans = new HashSet<>();

    moves.put("rook", new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
    moves.put("bishop", new int[][] {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}});
    moves.put("queen",
              new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}});
    List<List<int[]>> combMoves = new ArrayList<>();

    getCombMoves(pieces, 0, new ArrayList<>(), combMoves);

    for (List<int[]> combMove : combMoves)
      dfs(positions, n, combMove, (1 << n) - 1, ans);

    return ans.size();
  }

  private Map<String, int[][]> moves = new HashMap<>();

  private void getCombMoves(String[] pieces, int ithPiece, List<int[]> path,
                            List<List<int[]>> combMoves) {
    if (ithPiece == pieces.length) {
      combMoves.add(new ArrayList<>(path));
      return;
    }

    for (int[] move : moves.get(pieces[ithPiece])) {
      path.add(move);
      getCombMoves(pieces, ithPiece + 1, path, combMoves);
      path.remove(path.size() - 1);
    }
  }

  private void dfs(int[][] board, int n, List<int[]> combMove, int activeMask, Set<Long> ans) {
    if (activeMask == 0)
      return;
    ans.add(getHash(board));

    for (int nextActiveMask = 1; nextActiveMask < 1 << n; ++nextActiveMask) {
      if ((activeMask & nextActiveMask) != nextActiveMask)
        continue;

      // Make sure to copy the board.
      int[][] nextBoard = new int[n][];
      for (int i = 0; i < n; ++i)
        nextBoard[i] = board[i].clone();

      // Move the pieces that are active in this turn.
      for (int i = 0; i < n; ++i)
        if (((nextActiveMask >> i) & 1) == 1) {
          nextBoard[i][0] += combMove.get(i)[0];
          nextBoard[i][1] += combMove.get(i)[1];
        }

      // No two or more pieces occupy the same square.
      if (getUniqueSize(nextBoard) < n)
        continue;

      // Everything needs to be in the boundary.
      if (Arrays.stream(nextBoard).allMatch(p -> 1 <= p[0] && p[0] <= 8 && 1 <= p[1] && p[1] <= 8))
        dfs(nextBoard, n, combMove, nextActiveMask, ans);
    }
  }

  private long getHash(int[][] board) {
    long hash = 0;
    for (int[] pos : board)
      hash = (hash * 64) + (pos[0] - 1 << 3) + (pos[1] - 1);
    return hash;
  }

  private int getUniqueSize(int[][] board) {
    Set<Integer> unique = new HashSet<>();
    for (int[] pos : board)
      unique.add(pos[0] * 8 + pos[1]);
    return unique.size();
  }
}
