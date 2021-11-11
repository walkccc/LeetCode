class Solution {
 public:
  bool validTicTacToe(vector<string>& board) {
    const int countX = sum(board, 'X');
    const int countO = sum(board, 'O');

    if (countX < countO || countX - countO > 1)
      return false;
    if (isWinned(board, 'X') && countX == countO ||
        isWinned(board, 'O') && countX != countO)
      return false;

    return true;
  }

 private:
  int sum(const vector<string>& board, char c) {
    int ans = 0;

    for (const string& row : board)
      ans += count(begin(row), end(row), c);

    return ans;
  }

  bool isWinned(const vector<string>& board, char c) {
    vector<string> rotated = rotate(board);

    auto equalsToThree = [&c](const string& row) {
      return count(begin(row), end(row), c) == 3;
    };

    return any_of(begin(board), end(board), equalsToThree) ||
           any_of(begin(rotated), end(rotated), equalsToThree) ||
           board[0][0] == c && board[1][1] == c && board[2][2] == c ||
           board[0][2] == c && board[1][1] == c && board[2][0] == c;
  }

  vector<string> rotate(const vector<string>& board) {
    vector<string> rotated(3);

    for (const string& row : board)
      for (int i = 0; i < 3; ++i)
        rotated[i].push_back(row[i]);

    return rotated;
  }
};
