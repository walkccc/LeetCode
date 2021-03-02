enum State { INIT, VISITING, VISITED };

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
  bool hasCycle(const vector<vector<int>>& graph, int node,
                vector<State>& state) {
    if (state[node] == VISITING)
      return true;
    if (state[node] == VISITED)
      return false;

    state[node] = VISITING;
    for (const int child : graph[node])
      if (hasCycle(graph, child, state))
        return true;
    state[node] = VISITED;

    return false;
  }
};
