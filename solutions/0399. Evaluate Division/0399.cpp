class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    vector<double> ans;
    // graph[A][B] := A / B
    unordered_map<string, unordered_map<string, double>> graph;

    for (int i = 0; i < equations.size(); ++i) {
      const string& A = equations[i][0];
      const string& B = equations[i][1];
      graph[A][B] = values[i];
      graph[B][A] = 1 / values[i];
    }

    for (const auto& q : queries) {
      const string& A = q[0];
      const string& C = q[1];
      if (!graph.count(A) || !graph.count(C))
        ans.push_back(-1);
      else
        ans.push_back(divide(graph, A, C, unordered_set<string>()));
    }

    return ans;
  }

 private:
  // return A / C
  double divide(
      const unordered_map<string, unordered_map<string, double>>& graph,
      const string& A, const string& C, unordered_set<string>&& seen) {
    if (A == C)
      return 1.0;

    seen.insert(A);

    // value := A / B
    for (const auto& [B, value] : graph.at(A)) {
      if (seen.count(B))
        continue;
      const double res = divide(graph, B, C, move(seen));  // B / C
      if (res > 0)                                         // valid result
        return value * res;  // A / C = (A / B) * (B / C)
    }

    return -1;  // invalid result
  }
};
