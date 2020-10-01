class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    const enum State { INIT, VISITING, VISITED };

    vector<int> ans;
    vector<vector<int>> graph(numCourses);
    vector<State> state(numCourses);

    for (const vector<int>& p : prerequisites)
      graph[p[1]].push_back(p[0]);

    function<bool(int)> hasCycle = [&](int i) {
      if (state[i] == VISITING) return true;
      if (state[i] == VISITED) return false;

      state[i] = VISITING;
      for (const int neighbor : graph[i])
        if (hasCycle(neighbor))
          return true;
      state[i] = VISITED;
      ans.push_back(i);

      return false;
    };

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(i))
        return {};

    reverse(begin(ans), end(ans));
    return ans;
  }
};