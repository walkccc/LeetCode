class Solution {
 public:
  int findMinStep(string board, string hand) {
    const int ans = dfs(board + "#", hand, {});
    return ans == INT_MAX ? -1 : ans;
  }

 private:
  int dfs(string&& board, const string& hand,
          unordered_map<string, int>&& mem) {
    const string hashKey = board + '#' + hand;
    if (const auto it = mem.find(hashKey); it != mem.cend())
      return it->second;
    board = deDup(board);
    if (board == "#")
      return 0;

    unordered_set<char> boardSet = unordered_set(board.begin(), board.end());

    string hs;  // hand that is in board
    for (const char h : hand)
      if (boardSet.contains(h))
        hs += h;
    if (hs.empty())  // infeasible
      return INT_MAX;

    int ans = INT_MAX;

    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < hs.size(); ++j) {
        // Place hs[j] in board[i].
        const string& newHand = hs.substr(0, j) + hs.substr(j + 1);
        string newBoard = board.substr(0, i) + hs[j] + board.substr(i);
        const int res = dfs(std::move(newBoard), newHand, std::move(mem));
        if (res < INT_MAX)
          ans = min(ans, 1 + res);
      }

    return mem[hashKey] = ans;
  }

  string deDup(string board) {
    int start = 0;  // the start index of a color sequenece
    for (int i = 0; i < board.size(); ++i)
      if (board[i] != board[start]) {
        if (i - start >= 3)
          return deDup(board.substr(0, start) + board.substr(i));
        start = i;  // Meet a new sequence.
      }
    return board;
  }
};
