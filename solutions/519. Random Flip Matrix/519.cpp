class Solution {
 public:
  Solution(int n_rows, int n_cols)
      : rows(n_rows), cols(n_cols), total(n_rows * n_cols) {}

  vector<int> flip() {
    // All the candidates are used out.
    if (used.size() == total)
      return {};
    int index = rand() % total;
    while (used.count(index))
      index = ++index % total;
    used.insert(index);
    return {index / cols, index % cols};
  }

  void reset() {
    used = {};
  }

 private:
  unordered_set<int> used;
  int rows;
  int cols;
  int total;
};
