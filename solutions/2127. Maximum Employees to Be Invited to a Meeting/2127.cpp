enum class State { kInit, kVisiting, kVisited };

class Solution {
 public:
  int maximumInvitations(vector<int>& favorite) {
    const int n = favorite.size();
    int sumComponentsLength = 0;  // the component: a -> b -> c <-> x <- y
    vector<vector<int>> graph(n);
    vector<int> inDegrees(n);
    vector<int> maxChainLength(n, 1);
    queue<int> q;

    // Build the graph.
    for (int i = 0; i < n; ++i) {
      graph[i].push_back(favorite[i]);
      ++inDegrees[favorite[i]];
    }

    // Perform topological sorting.
    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : graph[u]) {
        if (--inDegrees[v] == 0)
          q.push(v);
        maxChainLength[v] = max(maxChainLength[v], 1 + maxChainLength[u]);
      }
    }

    for (int i = 0; i < n; ++i)
      if (favorite[favorite[i]] == i)
        // i <-> favorite[i] (the cycle's length = 2)
        sumComponentsLength += maxChainLength[i] + maxChainLength[favorite[i]];

    int maxCycleLength = 0;  // the cycle : a -> b -> c -> a
    vector<int> parent(n, -1);
    vector<bool> seen(n);
    vector<State> states(n);

    for (int i = 0; i < n; ++i)
      if (!seen[i])
        findCycle(graph, i, parent, seen, states, maxCycleLength);

    return max(sumComponentsLength / 2, maxCycleLength);
  }

 private:
  void findCycle(const vector<vector<int>>& graph, int u, vector<int>& parent,
                 vector<bool>& seen, vector<State>& states,
                 int& maxCycleLength) {
    seen[u] = true;
    states[u] = State::kVisiting;

    for (const int v : graph[u]) {
      if (!seen[v]) {
        parent[v] = u;
        findCycle(graph, v, parent, seen, states, maxCycleLength);
      } else if (states[v] == State::kVisiting) {
        // Find the cycle's length.
        int curr = u;
        int cycleLength = 1;
        while (curr != v) {
          curr = parent[curr];
          ++cycleLength;
        }
        maxCycleLength = max(maxCycleLength, cycleLength);
      }
    }

    states[u] = State::kVisited;
  }
};
