class Solution {
 public:
  int minimumDistance(string word) {
    // dp[i][j][k] := min distance with left finger on i-th char and right
    // finger on j-th char that already have written k first words
    dp.resize(27, vector<vector<int>>(27, vector<int>(word.length(), -1)));
    return minimumDistance(word, 26, 26, 0);
  }

 private:
  vector<vector<vector<int>>> dp;

  int minimumDistance(const string& word, int i, int j, int k) {
    if (k == word.length())
      return 0;
    if (dp[i][j][k] != -1)
      return dp[i][j][k];
    const int next = word[k] - 'A';
    const int moveLeft = dist(i, next) + minimumDistance(word, next, j, k + 1);
    const int moveRight = dist(j, next) + minimumDistance(word, i, next, k + 1);
    return dp[i][j][k] = min(moveLeft, moveRight);
  }

  int dist(int a, int b) {
    if (a == 26)  // first hovering state
      return 0;
    const int x1 = a / 6;
    const int y1 = a % 6;
    const int x2 = b / 6;
    const int y2 = b % 6;
    return abs(x1 - x2) + abs(y1 - y2);
  }
};
