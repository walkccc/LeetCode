class Solution {
 public:
  long long coloredCells(int n) {
    return 1LL * n * n + 1LL * (n - 1) * (n - 1);
  }
};
