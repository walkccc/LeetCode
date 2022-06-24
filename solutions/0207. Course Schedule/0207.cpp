enum class State { INIT, VISITING, VISITED };

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<State> state(numCourses);

    for (const auto& p : prerequisites)
      graph[p[1]].push_back(p[0]);

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, state))
        return false;

    return true;
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
