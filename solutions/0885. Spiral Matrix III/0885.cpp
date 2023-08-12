class Solution {
 public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    const vector<int> dx{1, 0, -1, 0};
    const vector<int> dy{0, 1, 0, -1};
    vector<vector<int>> ans{{rStart, cStart}};

    for (int i = 0; ans.size() < rows * cols; ++i)
      for (int step = 0; step < i / 2 + 1; ++step) {
        rStart += dy[i % 4];
        cStart += dx[i % 4];
        if (0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols)
          ans.push_back({rStart, cStart});
      }

    return ans;
  }
};
