class Solution {
 public:
  int removeBoxes(vector<int>& boxes) {
    const int n = boxes.size();
    vector<vector<vector<int>>> mem(n, vector<vector<int>>(n, vector<int>(n)));
    return removeBoxes(boxes, 0, n - 1, 0, mem);
  }

 private:
  // Returns the maximum score of boxes[i..j] if k boxes eqaul to boxes[j].
  int removeBoxes(const vector<int>& boxes, int i, int j, int k,
                  vector<vector<vector<int>>>& mem) {
    if (i > j)
      return 0;
    if (mem[i][j][k] > 0)
      return mem[i][j][k];

    int r = j;
    int sameBoxes = k + 1;
    while (r > 0 && boxes[r - 1] == boxes[r]) {
      --r;
      ++sameBoxes;
    }
    mem[i][j][k] = removeBoxes(boxes, i, r - 1, 0, mem) + sameBoxes * sameBoxes;

    for (int p = i; p < r; ++p)
      if (boxes[p] == boxes[r])
        mem[i][j][k] =
            max(mem[i][j][k], removeBoxes(boxes, i, p, sameBoxes, mem) +
                                  removeBoxes(boxes, p + 1, r - 1, 0, mem));

    return mem[i][j][k];
  }
};
