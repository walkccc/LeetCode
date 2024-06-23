class Solution {
 public:
  long long coloredCells(int n) {
    return 1L * n * n + 1L * (n - 1) * (n - 1);
  }
};
