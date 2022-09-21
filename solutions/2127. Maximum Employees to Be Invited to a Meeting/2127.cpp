enum class State { INIT, VISITING, VISITED };

class Solution {
 public:
  int maximumInvitations(vector<int>& favorite) {
    const int n = favorite.size();
    int sumComponentsLength = 0;  // component: a -> b -> c <-> x <- y
    vector<vector<int>> graph(n);
    vector<int> inDegree(n);
    vector<int> maxChainLength(n, 1);
    queue<int> q;

    // build graph
    for (int i = 0; i < n; ++i) {
      graph[i].push_back(favorite[i]);
      ++inDegree[favorite[i]];
    }

    // topology
    for (int i = 0; i < n; ++i)
      if (inDegree[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : graph[u]) {
        if (--inDegree[v] == 0)
          q.push(v);
        maxChainLength[v] = max(maxChainLength[v], 1 + maxChainLength[u]);
      }
    }

    for (int i = 0; i < n; ++i)
      if (favorite[favorite[i]] == i)
        // i <-> favorite[i] (cycle's length = 2)
        sumComponentsLength += maxChainLength[i] + maxChainLength[favorite[i]];

    int maxCycleLength = 0;  // cycle : a -> b -> c -> a
    vector<int> parent(n, -1);
    vector<bool> seen(n);
    vector<State> state(n);

    for (int i = 0; i < n; ++i)
      if (!seen[i])
        findCycle(graph, i, parent, seen, state, maxCycleLength);

    return max(sumComponentsLength / 2, maxCycleLength);
  }

 private:
  void findCycle(const vector<vector<int>>& graph, int u, vector<int>& parent,
                 vector<bool>& seen, vector<State>& state,
                 int& maxCycleLength) {
    seen[u] = true;
    state[u] = State::VISITING;

    for (const int v : graph[u]) {
      if (!seen[v]) {
        parent[v] = u;
        findCycle(graph, v, parent, seen, state, maxCycleLength);
      } else if (state[v] == State::VISITING) {
        // find the cycle's length
        int curr = u;
        int cycleLength = 1;
        while (curr != v) {
          curr = parent[curr];
          ++cycleLength;
        }
        maxCycleLength = max(maxCycleLength, cycleLength);
      }
    }

    state[u] = State::VISITED;
  }
};
