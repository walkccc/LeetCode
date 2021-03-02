class Solution {
 public:
  int numberOfPatterns(int m, int n) {
    int ans = 0;
    vector<vector<int>> across(10, vector<int>(10));
    vector<bool> seen(10);

    // set across numbers
    across[1][3] = across[3][1] = 2;
    across[1][7] = across[7][1] = 4;
    across[3][9] = across[9][3] = 6;
    across[7][9] = across[9][7] = 8;
    across[1][9] = across[9][1] = across[2][8] = across[8][2] =
    across[3][7] = across[7][3] = across[4][6] = across[6][4] = 5;

    ans += dfs(m, n, 1, 1, seen, across) * 4;  // 1, 3, 7, 9 are symmetric
    ans += dfs(m, n, 2, 1, seen, across) * 4;  // 2, 4, 6, 8 are symmetric
    ans += dfs(m, n, 5, 1, seen, across);      // 5

    return ans;
  }

 private:
  // [m, n] moves are valid
  int dfs(int m, int n, int curr, int level, vector<bool>& seen,
          const vector<vector<int>>& across) {
    if (level > n)
      return 0;

    seen[curr] = true;
    int ans = level >= m ? 1 : 0;

    for (int next = 1; next <= 9; ++next) {
      if (next == curr || seen[next])
        continue;
      const int acrossed = across[curr][next];
      if (acrossed == 0 || seen[acrossed])
        ans += dfs(m, n, next, level + 1, seen, across);
    }

    seen[curr] = false;

    return ans;
  }
};
