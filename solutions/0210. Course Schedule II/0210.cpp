enum class State { kInit, kVisiting, kVisited };

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<vector<int>> graph(numCourses);
    vector<State> states(numCourses);

    for (const vector<int>& prerequisite : prerequisites) {
      const int u = prerequisite[1];
      const int v = prerequisite[0];
      graph[u].push_back(v);
    }

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, states, ans))
        return {};

    reverse(ans.begin(), ans.end());
    return ans;
  }

 private:
  bool hasCycle(const vector<vector<int>>& graph, int u, vector<State>& states,
                vector<int>& ans) {
    if (states[u] == State::kVisiting)
      return true;
    if (states[u] == State::kVisited)
      return false;

    states[u] = State::kVisiting;
    for (const int v : graph[u])
      if (hasCycle(graph, v, states, ans))
        return true;
    states[u] = State::kVisited;
    ans.push_back(u);

    return false;
  }
};
