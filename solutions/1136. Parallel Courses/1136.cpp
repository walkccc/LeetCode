enum class State { INIT, VISITING, VISITED };

class Solution {
 public:
  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> graph(n);
    vector<State> state(n);
    vector<int> depth(n, 1);

    for (const auto& r : relations)
      graph[r[0] - 1].push_back(r[1] - 1);

    for (int i = 0; i < n; ++i)
      if (hasCycle(graph, i, state, depth))
        return -1;

    return *max_element(begin(depth), end(depth));
  }

 private:
  bool hasCycle(const vector<vector<int>>& graph, int u, vector<State>& state,
                vector<int>& depth) {
    if (state[u] == State::VISITING)
      return true;
    if (state[u] == State::VISITED)
      return false;

    state[u] = State::VISITING;
    for (const int v : graph[u]) {
      if (hasCycle(graph, v, state, depth))
        return true;
      depth[u] = max(depth[u], 1 + depth[v]);
    }
    state[u] = State::VISITED;

    return false;
  }
};
