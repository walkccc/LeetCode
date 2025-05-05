class Solution {
 public:
  int countCells(vector<vector<char>>& grid, string pattern) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
    string flattendGridRow;
    string flattendGridCol;

    // Flatten the grid for horizontal matching.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        flattendGridRow += grid[i][j];

    // Flatten the grid for vertical matching.
    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m; ++i)
        flattendGridCol += grid[i][j];

    // Find matching positions.
    const vector<vector<bool>> horizontalMatches =
        markMatchedCells(flattendGridRow, pattern, m, n, true);
    const vector<vector<bool>> verticalMatches =
        markMatchedCells(flattendGridCol, pattern, m, n, false);

    // Count overlapping match positions.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (horizontalMatches[i][j] && verticalMatches[i][j])
          ++ans;

    return ans;
  }

 private:
  static constexpr long kBase = 13;
  static constexpr long kHash = 1'000'000'007;

  vector<vector<bool>> markMatchedCells(const string& flattenedGrid,
                                        const string& pattern, int m, int n,
                                        bool isHorizontal) {
    vector<vector<bool>> matchMatrix(m, vector<bool>(n, false));
    vector<int> matchPrefix(flattenedGrid.length() + 1);
    vector<long> pows{1};  // pows[i] := kBase^i % kHash
    long patternHash = 0;
    long runningHash = 0;

    for (int i = 1; i < pattern.length(); ++i)
      pows.push_back((pows.back() * kBase) % kHash);

    for (const char c : pattern)
      patternHash = (patternHash * kBase + (c - 'a')) % kHash;

    for (int i = 0; i < flattenedGrid.length(); ++i) {
      runningHash = (runningHash * kBase + (flattenedGrid[i] - 'a')) % kHash;
      if (i >= pattern.length() - 1) {
        if (runningHash == patternHash) {  // Match found.
          ++matchPrefix[i - pattern.length() + 1];
          --matchPrefix[i + 1];
        }
        // Remove the contribution of the oldest letter.
        const long oldestLetterHash =
            (pows[pattern.length() - 1] *
             (flattenedGrid[i - pattern.length() + 1] - 'a')) %
            kHash;
        runningHash = (runningHash - oldestLetterHash + kHash) % kHash;
      }
    }

    for (int k = 0; k < flattenedGrid.length(); ++k) {
      matchPrefix[k] += (k > 0) ? matchPrefix[k - 1] : 0;
      if (matchPrefix[k] > 0) {
        const int i = isHorizontal ? k / n : k % m;
        const int j = isHorizontal ? k % n : k / m;
        matchMatrix[i][j] = true;
      }
    }

    return matchMatrix;
  }
};
