enum State { INIT, VISITING, VISITED };

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<vector<int>> graph(numCourses);
    vector<State> state(numCourses);

    for (const auto& p : prerequisites)
      graph[p[1]].push_back(p[0]);

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, state, ans))
        return {};

    reverse(begin(ans), end(ans));
    return ans;
  }

 private:
  bool hasCycle(const vector<vector<int>>& graph, int node,
                vector<State>& state, vector<int>& ans) {
    if (state[node] == VISITING)
      return true;
    if (state[node] == VISITED)
      return false;

    state[node] = VISITING;
    for (const int child : graph[node])
      if (hasCycle(graph, child, state, ans))
        return true;
    state[node] = VISITED;
    ans.push_back(node);

    return false;
  }
};
