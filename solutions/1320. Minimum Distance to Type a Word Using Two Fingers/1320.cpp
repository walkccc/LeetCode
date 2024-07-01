class Solution {
 public:
  int minimumDistance(string word) {
    vector<vector<vector<int>>> mem(
        27, vector<vector<int>>(27, vector<int>(word.length(), -1)));
    return minimumDistance(word, 26, 26, 0, mem);
  }

 private:
  // Returns the minimum distance to type `word`, where the left finger is on
  // the i-th letter, the right finger is on the j-th letter, and word[0..k)
  // have been written.
  int minimumDistance(const string& word, int i, int j, int k,
                      vector<vector<vector<int>>>& mem) {
    if (k == word.length())
      return 0;
    if (mem[i][j][k] != -1)
      return mem[i][j][k];
    const int c = word[k] - 'A';
    const int moveLeft = dist(i, c) + minimumDistance(word, c, j, k + 1, mem);
    const int moveRight = dist(j, c) + minimumDistance(word, i, c, k + 1, mem);
    return mem[i][j][k] = min(moveLeft, moveRight);
  }

  int dist(int a, int b) {
    if (a == 26)  // the first hovering state
      return 0;
    const int x1 = a / 6;
    const int y1 = a % 6;
    const int x2 = b / 6;
    const int y2 = b % 6;
    return abs(x1 - x2) + abs(y1 - y2);
  }
};
