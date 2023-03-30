enum class State { kInit, kVisiting, kVisited };

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<State> state(numCourses);

    for (const vector<int>& prerequisite : prerequisites) {
      const int u = prerequisite[1];
      const int v = prerequisite[0];
      graph[u].push_back(v);
    }

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, state))
        return false;

    return true;
  }

 private:
  bool hasCycle(const vector<vector<int>>& graph, int u, vector<State>& state) {
    if (state[u] == State::kVisiting)
      return true;
    if (state[u] == State::kVisited)
      return false;

    state[u] = State::kVisiting;
    for (const int v : graph[u])
      if (hasCycle(graph, v, state))
        return true;
    state[u] = State::kVisited;

    return false;
  }
};
