class SubrectangleQueries {
 public:
  SubrectangleQueries(vector<vector<int>>& rectangle) : rectangle(rectangle) {}

  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    updates.push_back({row1, col1, row2, col2, newValue});
  }

  int getValue(int row, int col) {
    for (int i = updates.size() - 1; i >= 0; --i) {
      auto [r1, c1, r2, c2, v] = updates[i];
      if (r1 <= row && row <= r2 && c1 <= col && col <= c2)
        return v;
    }
    return rectangle[row][col];
  }

 private:
  const vector<vector<int>>& rectangle;
  vector<array<int, 5>> updates;  // [r1, c1, r2, c2, v]
};
