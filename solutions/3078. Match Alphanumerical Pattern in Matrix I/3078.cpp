class Solution {
 public:
  vector<int> findPattern(vector<vector<int>>& board, vector<string>& pattern) {
    for (int x = 0; x < board.size() - pattern.size() + 1; ++x)
      for (int y = 0; y < board[0].size() - pattern[0].size() + 1; ++y)
        if (isMatch(board, x, y, pattern))
          return {x, y};
    return {-1, -1};
  }

 private:
  bool isMatch(const vector<vector<int>>& board, int x, int y,
               const vector<string>& pattern) {
    unordered_map<int, char> digitToLetter;
    unordered_map<char, int> letterToDigit;
    for (int i = 0; i < pattern.size(); ++i)
      for (int j = 0; j < pattern[i].size(); ++j) {
        const int digit = board[i + x][j + y];
        const char c = pattern[i][j];
        if (isdigit(c)) {
          if (c - '0' != digit)
            return false;
        } else {
          if (const auto it = digitToLetter.find(digit);
              it != digitToLetter.end() && it->second != c)
            return false;
          if (const auto it = letterToDigit.find(c);
              it != letterToDigit.end() && it->second != digit)
            return false;
          digitToLetter[digit] = c;
          letterToDigit[c] = digit;
        }
      }
    return true;
  }
};
