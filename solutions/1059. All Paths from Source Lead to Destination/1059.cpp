enum class State { kInit, kVisiting, kVisited };

class Solution {
 public:
  bool leadsToDestination(int n, vector<vector<int>>& edges, int source,
                          int destination) {
    vector<vector<int>> graph(n);
    vector<State> states(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
    }

    return acyclic(graph, source, destination, states);
  }

 private:
  bool acyclic(const vector<vector<int>>& graph, int u, int dest,
               vector<State>& states) {
    if (graph[u].empty())
      return u == dest;
    if (states[u] == State::kVisiting)
      return false;
    if (states[u] == State::kVisited)
      return true;

    states[u] = State::kVisiting;
    for (const int v : graph[u])
      if (!acyclic(graph, v, dest, states))
        return false;
    states[u] = State::kVisited;

    return true;
  }
};
