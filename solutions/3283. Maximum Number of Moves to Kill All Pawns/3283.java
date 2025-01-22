class Solution {
  public int maxMoves(int kx, int ky, int[][] positions) {
    final int n = positions.length;
    List<int[]> positionsList = new ArrayList<>(List.of(positions));
    positionsList.add(new int[] {kx, ky});
    Map<Integer, Integer> hashedPositionToIndex = new HashMap<>();
    // dist[i][j] := the minimum distance from positions[i] to positions[j]
    int[][] dist = new int[n + 1][n + 1];

    for (int i = 0; i < positionsList.size(); ++i) {
      final int x = positionsList.get(i)[0];
      final int y = positionsList.get(i)[1];
      hashedPositionToIndex.put(hash(x, y), i);
    }

    for (int sourceIndex = 0; sourceIndex < n + 1; ++sourceIndex)
      bfs(positionsList, sourceIndex, hashedPositionToIndex, dist);

    int kMaxMask = 1 << (n + 1);
    // dp[i][mask][turn] := the maximum (Alice) or the minimum (Bob) cost to
    // kill all pawns, where i is the current pawn, mask is the set of pawns
    // that have been killed, and turn is the current player's turn (0 for Alice
    // and 1 for Bob)
    int[][][] dp = new int[n + 1][1 << (n + 1)][2];

    for (int i = 0; i < n + 1; ++i)
      for (int mask = 0; mask < kMaxMask - 1; ++mask)
        dp[i][mask] = new int[] {-kMax, kMax};

    for (int mask = kMaxMask - 2; mask >= 0; --mask)
      for (int i = 0; i < n + 1; ++i)
        for (int turn = 0; turn < 2; ++turn)
          for (int j = 0; j < n; ++j) {
            if ((mask >> j & 1) == 1)
              continue;
            final int moves = dist[i][j] + dp[j][mask | 1 << j][1 - turn];
            dp[i][mask][turn] = turn == 0 ? Math.max(dp[i][mask][turn], moves) //
                                          : Math.min(dp[i][mask][turn], moves);
          }

    // Returns the maximum cost to kill all pawns, i.e., the original positions
    // array without the knight (kx, ky).
    return dp[n][1 << n][0];
  }

  private static final int kSize = 50;
  private static final int kMax = 1_000_000;
  private static final int[][] dirs = {{1, 2},   {2, 1},   {2, -1}, {1, -2},
                                       {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

  private int hash(int x, int y) {
    return x * kSize + y;
  }

  // Computes the distance between positions[sourceIndex] and other positions.
  private void bfs(List<int[]> positions, int sourceIndex,
                   Map<Integer, Integer> hashedPositionToIndex, int[][] dist) {
    final int sx = positions.get(sourceIndex)[0];
    final int sy = positions.get(sourceIndex)[1];
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(sx, sy)));
    boolean[][] seen = new boolean[kSize][kSize];
    seen[sx][sy] = true;
    int seenPositions = 0;

    for (int step = 0; !q.isEmpty() && seenPositions < positions.size(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.peek().getKey();
        final int j = q.poll().getValue();
        final int hashedPosition = hash(i, j);
        if (hashedPositionToIndex.containsKey(hashedPosition)) {
          dist[sourceIndex][hashedPositionToIndex.get(hashedPosition)] = step;
          ++seenPositions;
        }
        for (int[] dir : dirs) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x >= kSize || y < 0 || y >= kSize)
            continue;
          if (seen[x][y])
            continue;
          q.offer(new Pair<>(x, y));
          seen[x][y] = true;
        }
      }
  }
}
