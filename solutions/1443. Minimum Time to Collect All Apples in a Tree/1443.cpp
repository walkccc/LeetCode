class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> graph(n);
    vector<bool> seen(n);

    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    function<int(int)> dfs = [&](int num) {
      seen[num] = true;
      int totalCost = 0;

      for (int child : graph[num]) {
        if (seen[child]) continue;
        int cost = dfs(child);
        if (cost > 0 || hasApple[child])
          totalCost += cost + 2;
      }

      return totalCost;
    };

    return dfs(0);
  }
};