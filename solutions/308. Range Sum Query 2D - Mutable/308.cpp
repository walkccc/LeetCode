class FenwickTree {
 public:
  FenwickTree(int m, int n) : sums(m + 1, vector<int>(n + 1)) {}

  void add(int row, int col, int delta) {
    for (int i = row; i < sums.size(); i += lowbit(i))
      for (int j = col; j < sums[0].size(); j += lowbit(j))
        sums[i][j] += delta;
  }

  int get(int row, int col) {
    int sum = 0;
    for (int i = row; i > 0; i -= lowbit(i))
      for (int j = col; j > 0; j -= lowbit(j))
        sum += sums[i][j];
    return sum;
  }

 private:
  vector<vector<int>> sums;

  static inline int lowbit(int i) {
    return i & -i;
  }
};

class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix)
      : matrix(matrix), tree(matrix.size(), matrix[0].size()) {
    for (int i = 0; i < matrix.size(); ++i)
      for (int j = 0; j < matrix[0].size(); ++j)
        tree.add(i + 1, j + 1, matrix[i][j]);
  }

  void update(int row, int col, int val) {
    tree.add(row + 1, col + 1, val - matrix[row][col]);
    matrix[row][col] = val;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return tree.get(row2 + 1, col2 + 1) - tree.get(row1, col2 + 1) -
           tree.get(row2 + 1, col1) + tree.get(row1, col1);
  }

 private:
  vector<vector<int>> matrix;
  FenwickTree tree;
};
