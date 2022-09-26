class Solution {
 public:
  int unhappyFriends(int n, vector<vector<int>>& preferences,
                     vector<vector<int>>& pairs) {
    int ans = 0;
    vector<int> matches(n);
    vector<unordered_map<int, int>> prefer(n);

    for (const vector<int>& pair : pairs) {
      const int x = pair[0];
      const int y = pair[1];
      matches[x] = y;
      matches[y] = x;
    }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n - 1; ++j)
        prefer[i][preferences[i][j]] = j;

    for (int x = 0; x < n; ++x)
      for (const auto& [u, _] : prefer[x]) {
        const int y = matches[x];
        const int v = matches[u];
        if (prefer[x][u] < prefer[x][y] && prefer[u][x] < prefer[u][v]) {
          ++ans;
          break;
        }
      }

    return ans;
  }
};
