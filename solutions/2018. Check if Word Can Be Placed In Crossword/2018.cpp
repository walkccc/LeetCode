class Solution {
 public:
  bool placeWordInCrossword(vector<vector<char>>& board, string word) {
    for (const auto& state : {board, getRotated(board)})
      for (const auto& chars : state)
        for (const string& token : getTokens(join(chars)))
          for (const string& letters : {word, string(rbegin(word), rend(word))})
            if (letters.length() == token.length())
              if (canFit(letters, token))
                return true;
    return false;
  }

 private:
  vector<vector<char>> getRotated(const vector<vector<char>>& board) {
    const int m = board.size();
    const int n = board[0].size();
    vector<vector<char>> rotated(n, vector<char>(m));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        rotated[j][i] = board[i][j];
    return rotated;
  }

  vector<string> getTokens(const string& row) {
    vector<string> tokens;
    int start = 0;
    int end;
    string token;
    do {
      end = row.find('#', start);
      token = row.substr(start, end - start);
      if (!token.empty())
        tokens.push_back(token);
      start = end + 1;
    } while (end != string::npos);
    return tokens;
  }

  string join(const vector<char>& chars) {
    string joined;
    for (const char c : chars)
      joined += c;
    return joined;
  }

  bool canFit(const string& letters, const string& token) {
    for (int i = 0; i < letters.length(); ++i)
      if (token[i] != ' ' && token[i] != letters[i])
        return false;
    return true;
  }
};
