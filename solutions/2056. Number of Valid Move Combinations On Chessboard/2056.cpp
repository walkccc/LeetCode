class Solution {
 public:
  int countCombinations(vector<string>& pieces,
                        vector<vector<int>>& positions) {
    const int n = pieces.size();
    unordered_set<unsigned long long> ans;
    vector<vector<pair<int, int>>> combMoves;
    vector<pair<int, int>> board;

    getCombMoves(pieces, 0, {}, combMoves);

    for (const auto& pos : positions)
      board.emplace_back(pos[0], pos[1]);

    for (const auto& combMove : combMoves)
      dfs(board, n, combMove, (1 << n) - 1, ans);

    return ans.size();
  }

 private:
  const unordered_map<string, vector<pair<int, int>>> moves{
      {"rook", {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}},
      {"bishop", {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
      {"queen",
       {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}}};

  void getCombMoves(const vector<string>& pieces, int ithPiece,
                    vector<pair<int, int>>&& path,
                    vector<vector<pair<int, int>>>& combMoves) {
    if (ithPiece == pieces.size()) {
      combMoves.push_back(path);
      return;
    }

    for (const auto& move : moves.at(pieces[ithPiece])) {
      path.push_back(move);
      getCombMoves(pieces, ithPiece + 1, std::move(path), combMoves);
      path.pop_back();
    }
  }

  void dfs(const vector<pair<int, int>>& board, int n,
           const vector<pair<int, int>>& combMove, int activeMask,
           unordered_set<unsigned long long>& ans) {
    if (activeMask == 0)
      return;
    ans.insert(hash(board));

    for (int nextActiveMask = 1; nextActiveMask < 1 << n; ++nextActiveMask) {
      if ((activeMask & nextActiveMask) != nextActiveMask)
        continue;

      // make sure to copy the board
      auto nextBoard(board);

      // move pieces that are active in this turn
      for (int i = 0; i < n; ++i)
        if ((nextActiveMask >> i) & 1) {
          nextBoard[i].first += combMove[i].first;
          nextBoard[i].second += combMove[i].second;
        }

      // check no two or more pieces occupy the same square
      if (getUniqueSize(nextBoard) < n)
        continue;

      // check if all in boundary
      if (all_of(begin(nextBoard), end(nextBoard), [](const auto& piece) {
            const int x = piece.first;
            const int y = piece.second;
            return 1 <= x && x <= 8 && 1 <= y && y <= 8;
          }))
        dfs(nextBoard, n, combMove, nextActiveMask, ans);
    }
  }

  unsigned long long hash(const vector<pair<int, int>>& board) {
    unsigned long long hashed;
    for (const auto& [x, y] : board)
      hashed = (hashed * 64) + (x - 1 << 3) + (y - 1);
    return hashed;
  }

  int getUniqueSize(const vector<pair<int, int>>& board) {
    unordered_set<int> unique;
    for (const auto& [x, y] : board)
      unique.insert(x * 8 + y);
    return unique.size();
  }
};
