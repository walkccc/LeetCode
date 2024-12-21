class Solution {
 public:
  int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
    const int n = positions.size();
    positions.push_back({kx, ky});
    unordered_map<int, int> hashedPositionToIndex;
    // dist[i][j] := the minimum distance from positions[i] to positions[j]
    vector<vector<int>> dist(n + 1, vector<int>(n + 1));

    for (int i = 0; i < positions.size(); ++i) {
      const int x = positions[i][0];
      const int y = positions[i][1];
      hashedPositionToIndex[hash(x, y)] = i;
    }

    for (int sourceIndex = 0; sourceIndex < n + 1; ++sourceIndex)
      bfs(positions, sourceIndex, hashedPositionToIndex, dist);

    const int kMaxMask = 1 << (n + 1);
    // dp[i][mask][turn] := the maximum (Alice) or the minimum (Bob) cost to
    // kill all pawns, where i is the current pawn, mask is the set of pawns
    // that have been killed, and turn is the current player's turn (0 for Alice
    // and 1 for Bob)
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(1 << (n + 1), vector<int>(2)));

    for (int i = 0; i < n + 1; ++i)
      for (int mask = 0; mask < kMaxMask - 1; ++mask)
        dp[i][mask] = {-kMax, kMax};

    for (int mask = kMaxMask - 2; mask >= 0; --mask)
      for (int i = 0; i < n + 1; ++i)
        for (int turn = 0; turn < 2; ++turn)
          for (int j = 0; j < n; ++j) {
            if (mask >> j & 1)
              continue;
            const int moves = dist[i][j] + dp[j][mask | 1 << j][1 - turn];
            dp[i][mask][turn] = turn == 0 ? max(dp[i][mask][turn], moves)
                                          : min(dp[i][mask][turn], moves);
          }

    // Returns the maximum cost to kill all pawns, i.e., the original positions
    // array without the knight (kx, ky).
    return dp[n][1 << n][0];
  }

 private:
  static constexpr int kSize = 50;
  static constexpr int kMax = 1'000'000;
  static constexpr int dirs[8][2] = {{1, 2},   {2, 1},   {2, -1}, {1, -2},
                                     {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

  int hash(int x, int y) {
    return x * kSize + y;
  }

  // Computes the distance between positions[sourceIndex] and other positions.
  void bfs(const vector<vector<int>>& positions, int sourceIndex,
           const unordered_map<int, int>& hashedPositionToIndex,
           vector<vector<int>>& dist) {
    const int sx = positions[sourceIndex][0];
    const int sy = positions[sourceIndex][1];
    queue<pair<int, int>> q{{{sx, sy}}};
    vector<vector<bool>> seen(kSize, vector<bool>(kSize));
    seen[sx][sy] = true;
    int seenPositions = 0;

    for (int step = 0; !q.empty() && seenPositions < positions.size(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        if (const auto it = hashedPositionToIndex.find(hash(i, j));
            it != end(hashedPositionToIndex)) {
          dist[sourceIndex][it->second] = step;
          ++seenPositions;
        }
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x >= kSize || y < 0 || y >= kSize)
            continue;
          if (seen[x][y])
            continue;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }
  }
};
