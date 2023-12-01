class Solution {
 public:
  bool makesquare(vector<int>& matchsticks) {
    if (matchsticks.size() < 4)
      return false;

    const int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (perimeter % 4 != 0)
      return false;

    ranges::sort(matchsticks, greater<int>());
    return dfs(matchsticks, 0, vector<int>(4, perimeter / 4));
  }

 private:
  bool dfs(const vector<int>& matchsticks, int selected, vector<int>&& edges) {
    if (selected == matchsticks.size())
      return ranges::all_of(edges, [](int edge) { return edge == 0; });

    for (int i = 0; i < 4; ++i) {
      if (matchsticks[selected] > edges[i])
        continue;
      edges[i] -= matchsticks[selected];
      if (dfs(matchsticks, selected + 1, move(edges)))
        return true;
      edges[i] += matchsticks[selected];
    }

    return false;
  }
};
