enum class State { kInit, kVisiting, kVisited };

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    vector<State> states(graph.size());

    for (int i = 0; i < graph.size(); ++i)
      if (!hasCycle(graph, i, states))
        ans.push_back(i);

    return ans;
  }

 private:
  bool hasCycle(const vector<vector<int>>& graph, int u,
                vector<State>& states) {
    if (states[u] == State::kVisiting)
      return true;
    if (states[u] == State::kVisited)
      return false;

    states[u] = State::kVisiting;
    for (const int v : graph[u])
      if (hasCycle(graph, v, states))
        return true;
    states[u] = State::kVisited;

    return false;
  }
};
