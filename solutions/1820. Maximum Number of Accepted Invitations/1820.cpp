class Solution {
 public:
  int maximumInvitations(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
    vector<int> mates(n, -1);  // mates[i] := the i-th girl's mate

    for (int i = 0; i < m; ++i)
      if (canInvite(grid, i, vector<bool>(n), mates))
        ++ans;

    return ans;
  }

 private:
  // Returns true if the i-th boy can make an invitation.
  bool canInvite(const vector<vector<int>>& grid, int i, vector<bool>&& seen,
                 vector<int>& mates) {
    // The i-th boy asks each girl.
    for (int j = 0; j < seen.size(); ++j) {
      if (!grid[i][j] || seen[j])
        continue;
      seen[j] = true;
      if (mates[j] == -1 || canInvite(grid, mates[j], move(seen), mates)) {
        mates[j] = i;  // Match the j-th girl with i-th boy.
        return true;
      }
    }

    return false;
  }
};
