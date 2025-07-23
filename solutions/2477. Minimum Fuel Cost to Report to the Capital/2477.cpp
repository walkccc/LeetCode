class Solution {
 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    long ans = 0;
    vector<vector<int>> tree(roads.size() + 1);

    for (const vector<int>& road : roads) {
      const int u = road[0];
      const int v = road[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    dfs(tree, 0, -1, seats, ans);
    return ans;
  }

 private:
  int dfs(const vector<vector<int>>& tree, int u, int prev, int seats,
          long& ans) {
    int people = 1;
    for (const int v : tree[u])
      if (v != prev)
        people += dfs(tree, v, u, seats, ans);
    if (u > 0)
      // the number of cars needed = ceil(people / seats)
      ans += (people + seats - 1) / seats;
    return people;
  }
};
