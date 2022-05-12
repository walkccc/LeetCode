class Solution {
 public:
  int maximumInvitations(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
    vector<int> mate(n, -1);  // girl's mate

    for (int i = 0; i < m; ++i)
      if (canInvite(grid, i, vector<bool>(n), mate))
        ++ans;

    return ans;
  }

 private:
  // true if boy i can make an invitation
  bool canInvite(const vector<vector<int>>& grid, int i, vector<bool>&& seen,
                 vector<int>& mate) {
    // boy i ask each girl
    for (int j = 0; j < seen.size(); ++j) {
      if (!grid[i][j] || seen[j])
        continue;
      seen[j] = true;
      if (mate[j] == -1 || canInvite(grid, mate[j], move(seen), mate)) {
        mate[j] = i;  // match girl j w/ boy i
        return true;
      }
    }

    return false;
  }
};
