enum class State { INIT, VISITING, VISITED };

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    vector<State> state(graph.size());

    for (int i = 0; i < graph.size(); ++i)
      if (!hasCycle(graph, i, state))
        ans.push_back(i);

    return ans;
  }

 private:
  bool hasCycle(const vector<vector<int>>& graph, int u, vector<State>& state) {
    if (state[u] == State::VISITING)
      return true;
    if (state[u] == State::VISITED)
      return false;

    state[u] = State::VISITING;
    for (const int v : graph[u])
      if (hasCycle(graph, v, state))
        return true;
    state[u] = State::VISITED;

    return false;
  }
};
