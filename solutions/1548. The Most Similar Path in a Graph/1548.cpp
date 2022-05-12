class Solution {
 public:
  vector<int> mostSimilar(int n, vector<vector<int>>& roads,
                          vector<string>& names, vector<string>& targetPath) {
    this->names = names;
    this->targetPath = targetPath;
    // cost[i][j] := min cost to start from names[i] in path[j]
    this->cost.resize(names.size(), vector<int>(targetPath.size(), -1));
    // next[i][j] := best next of names[i] in path[j
    this->next.resize(names.size(), vector<int>(targetPath.size()));
    this->graph.resize(n);

    for (const auto& road : roads) {
      graph[road[0]].push_back(road[1]);
      graph[road[1]].push_back(road[0]);
    }

    int minDist = INT_MAX;
    int start = 0;

    for (int i = 0; i < n; ++i) {
      const int dist = dfs(i, 0);
      if (dist < minDist) {
        minDist = dist;
        start = i;
      }
    }

    vector<int> ans;

    while (ans.size() < targetPath.size()) {
      ans.push_back(start);
      start = next[start][ans.size() - 1];
    }

    return ans;
  }

 private:
  vector<string> names;
  vector<string> targetPath;
  vector<vector<int>> cost;
  vector<vector<int>> next;
  vector<vector<int>> graph;

  int dfs(int nameIndex, int pathIndex) {
    if (cost[nameIndex][pathIndex] != -1)
      return cost[nameIndex][pathIndex];

    const int editDist = names[nameIndex] != targetPath[pathIndex];
    if (pathIndex == targetPath.size() - 1)
      return editDist;

    int minDist = INT_MAX;

    for (const int v : graph[nameIndex]) {
      const int dist = dfs(v, pathIndex + 1);
      if (dist < minDist) {
        minDist = dist;
        next[nameIndex][pathIndex] = v;
      }
    }

    return cost[nameIndex][pathIndex] = editDist + minDist;
  }
};
