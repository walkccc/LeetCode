class Solution {
 public:
  int countCombinations(vector<string>& pieces,
                        vector<vector<int>>& positions) {
    const int n = pieces.size();
    unordered_set<long long> hashedBoards;
    // Stores all possible move combinations for `pieces`. Each element is a
    // vector of moves, one for each piece in the input order. e.g., if pieces =
    // ["rook", "bishop"], one element might be [[1,0], [1,1]], representing a
    // rook moving right and a bishop moving diagonally up-right.
    vector<vector<pair<int, int>>> pieceMovesList;

    getPieceMovesList(pieces, 0, {}, pieceMovesList);

    for (const vector<pair<int, int>>& pieceMoves : pieceMovesList)
      dfs(positions, n, pieceMoves, (1 << n) - 1, hashedBoards);

    return hashedBoards.size();
  }

 private:
  const unordered_map<string, vector<pair<int, int>>> kPieceToMoves{
      {"rook", {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}},
      {"bishop", {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
      {"queen",
       {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}}};

  // Generates all possible combinations of moves.
  void getPieceMovesList(const vector<string>& pieces, int i,
                         vector<pair<int, int>>&& path,
                         vector<vector<pair<int, int>>>& pieceMovesList) {
    if (i == pieces.size()) {
      pieceMovesList.push_back(path);
      return;
    }
    for (const pair<int, int>& move : kPieceToMoves.at(pieces[i])) {
      path.push_back(move);
      getPieceMovesList(pieces, i + 1, std::move(path), pieceMovesList);
      path.pop_back();
    }
  }

  // Performs a depth-first search to explore all possible board states.
  void dfs(const vector<vector<int>>& board, int n,
           const vector<pair<int, int>>& pieceMoves, int activeMask,
           unordered_set<long long>& hashedBoards) {
    if (activeMask == 0)
      return;
    hashedBoards.insert(getHash(board));
    for (int nextActiveMask = 1; nextActiveMask < 1 << n; ++nextActiveMask) {
      if ((activeMask & nextActiveMask) != nextActiveMask)
        continue;

      // Copy the board.
      vector<vector<int>> nextBoard = board;

      // Move the pieces that are active in this turn.
      for (int i = 0; i < n; ++i)
        if (nextActiveMask >> i & 1) {
          nextBoard[i][0] += pieceMoves[i].first;
          nextBoard[i][1] += pieceMoves[i].second;
        }

      // No two or more pieces occupy the same square.
      if (getUniqueSize(nextBoard) < n)
        continue;

      // Every piece needs to be in the boundary.
      if (ranges::all_of(nextBoard, [](const vector<int>& pos) {
        return 1 <= pos[0] && pos[0] <= 8 && 1 <= pos[1] && pos[1] <= 8;
      }))
        dfs(nextBoard, n, pieceMoves, nextActiveMask, hashedBoards);
    }
  }

  long long getHash(const vector<vector<int>>& board) {
    long long hash = 0;
    for (const vector<int>& pos : board)
      hash = (hash * 64) + ((pos[0] - 1) << 3) + (pos[1] - 1);
    return hash;
  }

  int getUniqueSize(const vector<vector<int>>& board) {
    unordered_set<int> unique;
    for (const vector<int>& pos : board)
      unique.insert(pos[0] * 8 + pos[1]);
    return unique.size();
  }
};
