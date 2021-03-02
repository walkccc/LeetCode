enum State { INIT, VISITING, VISITED };

class Solution {
 public:
  int minimumSemesters(int N, vector<vector<int>>& relations) {
    vector<vector<int>> graph(N + 1);
    vector<State> state(N + 1);
    vector<int> depth(N + 1, 1);

    for (const auto& r : relations)
      graph[r[0]].push_back(r[1]);

    for (int i = 1; i <= N; ++i)
      if (hasCycle(graph, i, state, depth))
        return -1;

    return *max_element(begin(depth), end(depth));
  }

 private:
  bool hasCycle(const vector<vector<int>>& graph, int node,
                vector<State>& state, vector<int>& depth) {
    if (state[node] == VISITING)
      return true;
    if (state[node] == VISITED)
      return false;

    state[node] = VISITING;
    for (const int child : graph[node]) {
      if (hasCycle(graph, child, state, depth))
        return true;
      depth[node] = max(depth[node], 1 + depth[child]);
    }
    state[node] = VISITED;

    return false;
  }
};
