class Solution {
 public:
  double soupServings(int n) {
    return n >= 4800 ? 1.0 : dfs((n + 24) / 25, (n + 24) / 25);
  }

 private:
  vector<vector<double>> mem =
      vector<vector<double>>(4800 / 25, vector<double>(4800 / 25));

  double dfs(int a, int b) {
    if (a <= 0 && b <= 0)
      return 0.5;
    if (a <= 0)
      return 1.0;
    if (b <= 0)
      return 0.0;
    if (mem[a][b] > 0)
      return mem[a][b];
    return mem[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) +
                               dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
  }
};
