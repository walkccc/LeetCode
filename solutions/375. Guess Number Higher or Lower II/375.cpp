class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> mem(n + 1, vector<int>(n + 1, INT_MAX));
    return getMoneyAmount(1, n, mem);
  }

 private:
  // Returns the minimum money you need to guarantee a win of picking i..j.
  int getMoneyAmount(int i, int j, vector<vector<int>>& mem) {
    if (i >= j)
      return 0;
    if (mem[i][j] != INT_MAX)
      return mem[i][j];

    for (int k = i; k <= j; ++k)
      mem[i][j] = min(mem[i][j], max(getMoneyAmount(i, k - 1, mem),
                                     getMoneyAmount(k + 1, j, mem)) +
                                     k);

    return mem[i][j];
  }
};
