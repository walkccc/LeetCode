class Solution {
 public:
  bool checkContradictions(vector<vector<string>>& equations,
                           vector<double>& values) {
    // convert string to int for better perfermance
    unordered_map<string, int> strToInt;

    for (const auto& e : equations) {
      const auto& u = e[0];
      const auto& v = e[1];
      if (!strToInt.count(u))
        strToInt[u] = strToInt.size();
      if (!strToInt.count(v))
        strToInt[v] = strToInt.size();
    }

    vector<vector<pair<int, double>>> graph(strToInt.size());
    vector<double> seen(graph.size());

    for (int i = 0; i < equations.size(); ++i) {
      const auto& u = strToInt.at(equations[i][0]);
      const auto& v = strToInt.at(equations[i][1]);
      graph[u].emplace_back(v, values[i]);
      graph[v].emplace_back(u, 1 / values[i]);
    }

    for (int i = 0; i < graph.size(); ++i)
      if (!seen[i] && dfs(graph, i, seen, 1.0))
        return true;

    return false;
  }

 private:
  bool dfs(const vector<vector<pair<int, double>>>& graph, int u,
           vector<double>& seen, double val) {
    if (seen[u])
      return abs(val / seen[u] - 1) > 1e-5;

    seen[u] = val;
    for (const auto& [v, w] : graph[u])
      if (dfs(graph, v, seen, val / w))
        return true;

    return false;
  }
};
